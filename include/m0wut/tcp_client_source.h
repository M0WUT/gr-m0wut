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

#ifndef INCLUDED_M0WUT_TCP_CLIENT_SOURCE_H
#define INCLUDED_M0WUT_TCP_CLIENT_SOURCE_H

#include <m0wut/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace m0wut {

    /*!
     * \brief <+description of block+>
     * \ingroup m0wut
     *
     */
    class M0WUT_API tcp_client_source : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<tcp_client_source> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of m0wut::tcp_client_source.
       *
       * To avoid accidental use of raw pointers, m0wut::tcp_client_source's
       * constructor is in a private implementation
       * class. m0wut::tcp_client_source::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::string addr = "127.0.0.1", int pot = 8080, int packetSize = 1024);
    };

  } // namespace m0wut
} // namespace gr

#endif /* INCLUDED_M0WUT_TCP_CLIENT_SOURCE_H */

