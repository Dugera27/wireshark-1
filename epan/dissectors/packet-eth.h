/* packet-eth.h
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __PACKET_ETH_H__
#define __PACKET_ETH_H__

#include "ws_symbol_export.h"

typedef struct _eth_hdr {
	address dst;
	address src;
	guint16 type;
} eth_hdr;

WS_DLL_PUBLIC
void capture_eth(const guchar *, int, int, packet_counts *);

void add_ethernet_trailer(packet_info *pinfo, proto_tree *tree, proto_tree *fh_tree,
			  int trailer_id, tvbuff_t *tvb, tvbuff_t *trailer_tvb,
			  int fcs_len);

#endif
