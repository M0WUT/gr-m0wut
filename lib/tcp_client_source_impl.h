/* -*- c++ -*- */
/*
 * Copyright 2020 gr-m0wut author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_M0WUT_TCP_CLIENT_SOURCE_IMPL_H
#define INCLUDED_M0WUT_TCP_CLIENT_SOURCE_IMPL_H

#include <m0wut/tcp_client_source.h>
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h>
#include <assert.h>
#include <errno.h>

namespace gr {
  namespace m0wut {

    class tcp_client_source_impl : public tcp_client_source
    {
     private:
      int port;
      int packetSize;
      int sock;

     public:
      tcp_client_source_impl(std::string addr, int pot, int packetSize);
      ~tcp_client_source_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace m0wut
} // namespace gr

#endif /* INCLUDED_M0WUT_TCP_CLIENT_SOURCE_IMPL_H */

