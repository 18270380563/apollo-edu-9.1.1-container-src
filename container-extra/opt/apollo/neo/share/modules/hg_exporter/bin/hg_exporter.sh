#/bin/bash

# kill process
ps -ef | grep -w "hg_car_service" | grep -v grep | awk '{print $2}' | xargs kill -9 2>/dev/null
ps -ef | grep -w "hg_canbus_chassis" | grep -v grep | awk '{print $2}' | xargs kill -9 2>/dev/null

# set env
CAR_ID_FILE="/home/apollo/.apollo/HG_VIN.txt"
if [[ ! -f $CAR_ID_FILE ]];then
   car_id=`date "+%Y%m%d%H%M%S"`
   echo apollo_${car_id} > $CAR_ID_FILE
fi
export CAR_ID_FILE=$CAR_ID_FILE
echo "set env CAR_ID_FILE=$CAR_ID_FILE"
export HG_CAR_STATUS_FILE="/home/apollo/.apollo/hg_canbus_data.json"
echo "set env HG_CAR_STATUS_FILE=$HG_CAR_STATUS_FILE"

# start process
hg_canbus_chassis &

bin_dir="/opt/apollo/neo/share/modules/hg_exporter/bin"
TARGET_ARCH="$(uname -m)"
if [[ "${TARGET_ARCH}" == "x86_64" ]]; then
    ${bin_dir}/hg_car_service.x86_64
elif [[ "${TARGET_ARCH}" == "aarch64" ]]; then
    ${bin_dir}/hg_car_service.aarch64
else
    echo "arch ${TARGET_ARCH} is not support"
fi

echo "hg_exporter finished"