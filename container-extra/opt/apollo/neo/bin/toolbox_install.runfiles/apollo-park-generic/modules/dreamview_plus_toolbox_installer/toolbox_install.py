#!/usr/bin/env python3

###############################################################################
# Copyright 2023 The Apollo Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
###############################################################################
"""
ToolBox install script
"""

import argparse
import os
import sys
import shutil

APOLLO_ENV_WORKROOT = os.getenv('APOLLO_ENV_WORKROOT', '/apollo_workspace')
APOLLO_DISTRIBUTION_HOME = os.getenv(
    'APOLLO_DISTRIBUTION_HOME', '/opt/apollo/neo')
CONF_DIR = os.path.join(APOLLO_DISTRIBUTION_HOME, 'share')

TOOL_CONFIGS = [
    # path, conf_names
    ('modules/private_tools/tile_map_images_creator/conf',
     ['image_creator_conf.pb.txt']),
    ('modules/private_tools/map_tool/conf',
     ['map_validator_checker_conf.pb.txt', 'map_validator_errcode_conf.pb.txt']),
    ('modules/loam_velodyne/conf', ['laser_multiscan_registration_conf.pb.txt',
     'laser_odometry_conf.pb.txt', 'localization_conf.pb.txt']),
    ('modules/dreamview_plus_plugins/calibration_tool/conf',
     ['calibration_conf.pb.txt'])
]


def update(profile, force):
    """ update
    """
    profile_path = os.path.join(APOLLO_ENV_WORKROOT, 'profiles', profile)
    if not os.path.isdir(profile_path):
        print(f'profile [{profile}] not exist!')
        sys.exit(1)

    print('Begin install hmi_mode conf...')
    hmi_mode_conf_path = 'modules/dreamview_plus/conf/hmi_modes'
    hmi_mode_dir = os.path.join(profile_path, hmi_mode_conf_path)
    os.makedirs(hmi_mode_dir, exist_ok=True)
    src_path = os.path.join(
        CONF_DIR, 'modules/dreamview_plus_toolbox_installer/hmi_mode_conf')
    for file in os.listdir(src_path):
        if force or not os.path.exists(os.path.join(hmi_mode_dir, file)):
            print(f'copy {file} into {hmi_mode_dir}')
            shutil.copy(os.path.join(src_path, file), hmi_mode_dir)

    print('Begin install modules conf...')
    for (path, conf_names) in TOOL_CONFIGS:
        path_dir = os.path.join(profile_path, path)
        if os.path.exists(path_dir):
            if not os.path.isdir(path_dir):
                print(f'{path} is not a directory!')
                sys.exit(1)
        else:
            os.makedirs(path_dir)
        for conf_name in conf_names:
            filename = os.path.join(path_dir, conf_name)
            if force or not os.path.exists(filename):
                print(f'copy {conf_name} to {filename}')
                shutil.copyfile(os.path.join(
                    CONF_DIR, path, conf_name), filename)
    print('Finish install toolbox.')


def main():
    """ Main Method
    """
    parser = argparse.ArgumentParser(description='Toolbox Install Script')
    parser.add_argument(
        '-p', '--profile', help='profile name', required=True)
    parser.add_argument(
        '-f', '--force', action='store_true', help='force overwrite')
    args = parser.parse_args()

    update(args.profile, args.force)


if __name__ == '__main__':
    main()
