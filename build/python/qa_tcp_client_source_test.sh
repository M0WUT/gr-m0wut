#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir="/home/dan/GNU_Radio/M0WUT/gr-m0wut/python"
export GR_CONF_CONTROLPORT_ON=False
export PATH="/home/dan/GNU_Radio/M0WUT/gr-m0wut/build/python":$PATH
export LD_LIBRARY_PATH="":$LD_LIBRARY_PATH
export PYTHONPATH=/home/dan/GNU_Radio/M0WUT/gr-m0wut/build/swig:$PYTHONPATH
/usr/bin/python3.6 /home/dan/GNU_Radio/M0WUT/gr-m0wut/python/qa_tcp_client_source.py 
