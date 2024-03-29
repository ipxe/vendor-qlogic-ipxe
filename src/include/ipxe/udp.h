#ifndef _IPXE_UDP_H
#define _IPXE_UDP_H

/** @file
 *
 * UDP protocol
 *
 * This file defines the iPXE UDP API.
 *
 */

FILE_LICENCE ( GPL2_OR_LATER );

#include <stddef.h>
#include <ipxe/iobuf.h>
#include <ipxe/tcpip.h>
#include <ipxe/if_ether.h>

struct xfer_interface;

/**
 * UDP constants
 */

#define UDP_MAX_HLEN	72
#define UDP_MAX_TXIOB	ETH_MAX_MTU
#define UDP_MIN_TXIOB	ETH_ZLEN

/**
 * A UDP header
 */
struct udp_header {
	/** Source port */
	uint16_t src;
	/** Destination port */
	uint16_t dest;
	/** Length */
	uint16_t len;
	/** Checksum */
	uint16_t chksum;
};

extern int udp_open_promisc ( struct xfer_interface *xfer );
extern int udp_open ( struct xfer_interface *xfer, struct sockaddr *peer,
		      struct sockaddr *local );

#endif /* _IPXE_UDP_H */

