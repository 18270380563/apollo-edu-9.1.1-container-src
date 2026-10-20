"""network tf"""
import os
import warnings
warnings.filterwarnings("ignore", category=FutureWarning)
import tensorflow as tf
import modules.control.vehicle_calibration.common.logging as logging

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

class NeuralNetworkTF(object):
    """
    neural network for auto calibration
    """

    def __init__(self, layer):
        """
        init function
        """
        warnings.filterwarnings("ignore", category=FutureWarning)
        tf.compat.v1.reset_default_graph()
        self.layer = layer
        self.session = tf.compat.v1.Session()

    def create_placeholder(self, n_x, n_y):
        """
        create placeholder
        """
        warnings.filterwarnings("ignore", category=FutureWarning)
        with tf.compat.v1.name_scope("placeholders"):  # Use name scope to avoid potential conflicts
            self.X = tf.keras.Input(shape=(n_x,), name="X")
            self.Y = tf.keras.Input(shape=(n_y,), name="Y")

    def forward_propagation(self, X, params):
        """
        forward propagation
        """
        warnings.filterwarnings("ignore", category=FutureWarning)
        Z1 = tf.add(tf.matmul(X, params['W1']), params['b1'])
        A1 = tf.math.sigmoid(Z1)
        Z2 = tf.add(tf.matmul(A1, params['W2']), params['b2'])
        return Z2

    def initialize_parameters(self):
        """
        initialize weight and bias
        """
        warnings.filterwarnings("ignore", category=FutureWarning)
        xavier_initializer = tf.initializers.GlorotUniform()
        W1 = tf.compat.v1.get_variable('W1', [self.layer[0], self.layer[1]], initializer=xavier_initializer)
        W2 = tf.compat.v1.get_variable('W2', [self.layer[1], self.layer[2]], initializer=xavier_initializer)
        b1 = tf.compat.v1.get_variable('b1', [1, self.layer[1]], initializer=tf.zeros_initializer())
        b2 = tf.compat.v1.get_variable('b2', [1, self.layer[2]], initializer=tf.zeros_initializer())
        params = {'W1': W1,
                  'W2': W2,
                  'b1': b1,
                  'b2': b2}
        return params

    def train(self, X_train, Y_train, X_test=None, Y_test=None, alpha=0.01, w_lambda=0.01,
              num_epoch=10000, print_loss=False):
        """
        train model
        """
        tf.compat.v1.disable_eager_execution()
        warnings.filterwarnings("ignore", category=FutureWarning)
        (m, n_x) = X_train.shape
        (_, n_y) = Y_train.shape
        costs = []

        self.create_placeholder(n_x, n_y)
        params = self.initialize_parameters()
        self.Y_hat = self.forward_propagation(self.X, params)

        # loss function
        self.cost = tf.reduce_mean(tf.square((self.Y - self.Y_hat)))
        tf.compat.v1.add_to_collection("losses", tf.keras.regularizers.l2(w_lambda)(params['W1']))
        tf.compat.v1.add_to_collection("losses", tf.keras.regularizers.l2(w_lambda)(params['W2']))
        tf.compat.v1.add_to_collection("losses", self.cost)
        loss = tf.compat.v1.add_n(tf.compat.v1.get_collection("losses"))
        optimizer = tf.compat.v1.train.AdamOptimizer(learning_rate=alpha)

        def loss_function(loss):
            """return loss"""
            return loss

        if tf.executing_eagerly():
            grads_and_vars = optimizer.compute_gradients(loss_function(loss))
            train_op = optimizer.apply_gradients(grads_and_vars)
        else:
            train_op = optimizer.minimize(loss)

        self.session.run(tf.compat.v1.global_variables_initializer())
        for epoch in range(num_epoch):
            feed_dict = {self.X: X_train, self.Y: Y_train}
            _, epoch_cost = self.session.run([train_op, loss], feed_dict=feed_dict)
            if print_loss and epoch % 100 == 0:
                logging.info("loss after epoch %d: %f" % (epoch, epoch_cost))
                # print("loss after epoch %d: %f" % (epoch, epoch_cost))
            if epoch % 10 == 0:
                costs.append(epoch_cost)

        # store params
        params = self.session.run(params)

        # check accuracy
        train_cost, test_cost = 0.0, 0.0
        with self.session.as_default():
            train_cost = self.cost.eval(feed_dict={self.X: X_train, self.Y: Y_train})
            if X_test is not None and Y_test is not None:
                test_cost = self.cost.eval(feed_dict={self.X: X_test, self.Y: Y_test})

        return params, train_cost, test_cost

    def predict(self, X_data, Y_data=None):
        """
        predict output, if Y is provided, return cost; else, return predicted Y
        """
        warnings.filterwarnings("ignore", category=FutureWarning)
        if Y_data is not None:
            with self.session.as_default():
                test_cost = self.cost.eval(feed_dict={self.X: X_data, self.Y: Y_data})
                return test_cost
        else:
            Y_pred = self.session.run(self.Y_hat, feed_dict={self.X: X_data})
        return Y_pred
