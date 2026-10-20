#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
    Usage: hg_exporter
"""
import subprocess

subprocess.run(
    "bash /opt/apollo/neo/share/modules/hg_exporter/bin/hg_exporter.sh", shell=True, check=True)
