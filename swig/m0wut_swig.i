/* -*- c++ -*- */

#define M0WUT_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "m0wut_swig_doc.i"

%{
#include "m0wut/tcp_client_source.h"
%}

%include "m0wut/tcp_client_source.h"
GR_SWIG_BLOCK_MAGIC2(m0wut, tcp_client_source);
