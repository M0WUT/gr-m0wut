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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "tcp_client_source_impl.h"

namespace gr {
  namespace m0wut {

    tcp_client_source::sptr
    tcp_client_source::make(std::string addr, int pot, int packetSize)
    {
      return gnuradio::get_initial_sptr
        (new tcp_client_source_impl(addr, pot, packetSize));
    }


    /*
     * The private constructor
     */
    tcp_client_source_impl::tcp_client_source_impl(std::string addr, int pot, int packetSize)
      : gr::sync_block("tcp_client_source",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, packetSize * sizeof(int32_t)))
    {
      this->port = pot;  // Stupid typo I can't be bothered propagating a fix for
      this->packetSize = packetSize;

      struct sockaddr_in serv_addr; 


      // Creat socket
      if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
      { 
        perror("SDR Client: Error creating socket");
        exit(EXIT_FAILURE);
      } 
  
      serv_addr.sin_family = AF_INET; 
      serv_addr.sin_port = htons(port); 
      
      // Convert IPv4 and IPv6 addresses from text to binary form 
      if(inet_pton(AF_INET, addr.c_str(), &serv_addr.sin_addr) <= 0)  
      { 
        char buffer[1024];
        sprintf(buffer, "SDR Client: Supplied Server IP (%s) not in a recognised format", addr.c_str());
        perror(buffer);
        exit(EXIT_FAILURE);
      } 
  
      if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
      { 
        char buffer[1024];
        sprintf(buffer, "SDR Client: Failed to connector to server at %s:%d", addr.c_str(), port);
        perror(buffer);
        exit(EXIT_FAILURE);
      }
    }

    /*
     * Our virtual destructor.
     */
    tcp_client_source_impl::~tcp_client_source_impl()
    {
    }

    int
    tcp_client_source_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      int32_t *out = (int32_t *) output_items[0];
      char* x = (char *) out;
      int bytesReceived = 0;
      int bytesRequested = packetSize * sizeof(output_items[0]);
      
      while(bytesReceived < bytesRequested) {
      

        int bytesRead = read(sock, &x[bytesReceived], bytesRequested - bytesReceived);
        
        if(bytesRead <= 0) {
          if(!errno)
            perror("SDR Client: No more data available from server");    
          else
            perror("SDR Client: Unhandled error when reading from server");
              
          printf("SDR CLient: Shutting down!\n");
          exit(EXIT_FAILURE);
        }
              
        bytesReceived += bytesRead;
      

        
      }
      // Tell runtime system how many output items we produced.
      return 1;
    }

  } /* namespace m0wut */
} /* namespace gr */

