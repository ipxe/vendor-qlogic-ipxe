#include <errno.h>
#include <ipxe/errortab.h>

/*
 * This table was generated from the relevant section of errno.h using
 *
 * perl -ne 'if ( /(PXENV_STATUS_(\S+))/ ) {
 *	$code = $1; $msg = $2;
 *	$msg =~ s/_/ /g; $msg = ucfirst lc $msg;
 *	$msg =~ s/(tftp|udp|arp|undi|bis|binl|pxenv|pxe|dhcp)/uc $1/ieg;
 *	print "\t{ $code, \"$msg\" },\n";
 *	}'
 *
 * followed by a little manual tweaking.
 *
 */
struct errortab pxe_errortab[] __errortab = {
	{ PXENV_STATUS_SUCCESS, "Success" },
	{ PXENV_STATUS_FAILURE, "Failure" },
	{ PXENV_STATUS_BAD_FUNC, "Bad function" },
	{ PXENV_STATUS_UNSUPPORTED, "Unsupported function" },
	{ PXENV_STATUS_KEEP_UNDI, "Keep UNDI" },
	{ PXENV_STATUS_KEEP_ALL, "Keep all" },
	{ PXENV_STATUS_OUT_OF_RESOURCES, "Out of resources" },
	{ PXENV_STATUS_ARP_TIMEOUT, "ARP timeout" },
	{ PXENV_STATUS_UDP_CLOSED, "UDP closed" },
	{ PXENV_STATUS_UDP_OPEN, "UDP open" },
	{ PXENV_STATUS_TFTP_CLOSED, "TFTP closed" },
	{ PXENV_STATUS_TFTP_OPEN, "TFTP open" },
	{ PXENV_STATUS_MCOPY_PROBLEM, "Memory copy problem" },
	{ PXENV_STATUS_BIS_INTEGRITY_FAILURE, "BIS integrity failure" },
	{ PXENV_STATUS_BIS_VALIDATE_FAILURE, "BIS validation failure" },
	{ PXENV_STATUS_BIS_INIT_FAILURE, "BIS init failure" },
	{ PXENV_STATUS_BIS_SHUTDOWN_FAILURE, "BIS shutdown failure" },
	{ PXENV_STATUS_BIS_GBOA_FAILURE, "BIS GBOA failure" },
	{ PXENV_STATUS_BIS_FREE_FAILURE, "BIS free failure" },
	{ PXENV_STATUS_BIS_GSI_FAILURE, "BIS GSI failure" },
	{ PXENV_STATUS_BIS_BAD_CKSUM, "BIS bad checksum" },
	{ PXENV_STATUS_TFTP_CANNOT_ARP_ADDRESS, "TFTP cannot ARP address" },
	{ PXENV_STATUS_TFTP_OPEN_TIMEOUT, "TFTP open timeout" },
	{ PXENV_STATUS_TFTP_UNKNOWN_OPCODE, "TFTP unknown opcode" },
	{ PXENV_STATUS_TFTP_READ_TIMEOUT, "TFTP read timeout" },
	{ PXENV_STATUS_TFTP_ERROR_OPCODE, "TFTP error opcode" },
	{ PXENV_STATUS_TFTP_CANNOT_OPEN_CONNECTION,
	  "TFTP cannot open connection" },
	{ PXENV_STATUS_TFTP_CANNOT_READ_FROM_CONNECTION,
	  "TFTP cannot read from connection" },
	{ PXENV_STATUS_TFTP_TOO_MANY_PACKAGES, "TFTP too many packages" },
	{ PXENV_STATUS_TFTP_FILE_NOT_FOUND, "TFTP file not found" },
	{ PXENV_STATUS_TFTP_ACCESS_VIOLATION, "TFTP access violation" },
	{ PXENV_STATUS_TFTP_NO_MCAST_ADDRESS, "TFTP no mcast address" },
	{ PXENV_STATUS_TFTP_NO_FILESIZE, "TFTP no filesize" },
	{ PXENV_STATUS_TFTP_INVALID_PACKET_SIZE, "TFTP invalid packet size" },
	{ PXENV_STATUS_DHCP_TIMEOUT, "DHCP timeout" },
	{ PXENV_STATUS_DHCP_NO_IP_ADDRESS, "DHCP no ip address" },
	{ PXENV_STATUS_DHCP_NO_BOOTFILE_NAME, "DHCP no bootfile name" },
	{ PXENV_STATUS_DHCP_BAD_IP_ADDRESS, "DHCP bad ip address" },
	{ PXENV_STATUS_UNDI_INVALID_FUNCTION, "UNDI invalid function" },
	{ PXENV_STATUS_UNDI_MEDIATEST_FAILED, "UNDI mediatest failed" },
	{ PXENV_STATUS_UNDI_CANNOT_INIT_NIC_FOR_MCAST,
	  "UNDI cannot initialise NIC for multicast" },
	{ PXENV_STATUS_UNDI_CANNOT_INITIALIZE_NIC,
	  "UNDI cannot initialise NIC" },
	{ PXENV_STATUS_UNDI_CANNOT_INITIALIZE_PHY,
	  "UNDI cannot initialise PHY" },
	{ PXENV_STATUS_UNDI_CANNOT_READ_CONFIG_DATA,
	  "UNDI cannot read config data" },
	{ PXENV_STATUS_UNDI_CANNOT_READ_INIT_DATA,
	  "UNDI cannot read init data" },
	{ PXENV_STATUS_UNDI_BAD_MAC_ADDRESS, "UNDI bad MAC address" },
	{ PXENV_STATUS_UNDI_BAD_EEPROM_CHECKSUM, "UNDI bad EEPROM checksum" },
	{ PXENV_STATUS_UNDI_ERROR_SETTING_ISR, "UNDI error setting ISR" },
	{ PXENV_STATUS_UNDI_INVALID_STATE, "UNDI invalid state" },
	{ PXENV_STATUS_UNDI_TRANSMIT_ERROR, "UNDI transmit error" },
	{ PXENV_STATUS_UNDI_INVALID_PARAMETER, "UNDI invalid parameter" },
	{ PXENV_STATUS_BSTRAP_PROMPT_MENU, "Bootstrap prompt menu" },
	{ PXENV_STATUS_BSTRAP_MCAST_ADDR, "Bootstrap mcast addr" },
	{ PXENV_STATUS_BSTRAP_MISSING_LIST, "Bootstrap missing list" },
	{ PXENV_STATUS_BSTRAP_NO_RESPONSE, "Bootstrap no response" },
	{ PXENV_STATUS_BSTRAP_FILE_TOO_BIG, "Bootstrap file too big" },
	{ PXENV_STATUS_BINL_CANCELED_BY_KEYSTROKE,
	  "BINL canceled by keystroke" },
	{ PXENV_STATUS_BINL_NO_PXE_SERVER, "BINL no PXE server" },
	{ PXENV_STATUS_NOT_AVAILABLE_IN_PMODE,
	  "Not available in protected mode" },
	{ PXENV_STATUS_NOT_AVAILABLE_IN_RMODE, "Not available in real mode" },
	{ PXENV_STATUS_BUSD_DEVICE_NOT_SUPPORTED,
	  "BUSD device not supported" },
	{ PXENV_STATUS_LOADER_NO_FREE_BASE_MEMORY,
	  "Loader no free base memory" },
	{ PXENV_STATUS_LOADER_NO_BC_ROMID, "Loader no Base Code ROM ID" },
	{ PXENV_STATUS_LOADER_BAD_BC_ROMID, "Loader bad Base Code ROM ID" },
	{ PXENV_STATUS_LOADER_BAD_BC_RUNTIME_IMAGE,
	  "Loader bad Base Code runtime image" },
	{ PXENV_STATUS_LOADER_NO_UNDI_ROMID, "Loader no UNDI ROM ID" },
	{ PXENV_STATUS_LOADER_BAD_UNDI_ROMID, "Loader bad UNDI ROM ID" },
	{ PXENV_STATUS_LOADER_BAD_UNDI_DRIVER_IMAGE,
	  "Loader bad UNDI driver image" },
	{ PXENV_STATUS_LOADER_NO_PXE_STRUCT, "Loader no !PXE struct" },
	{ PXENV_STATUS_LOADER_NO_PXENV_STRUCT, "Loader no PXENV+ struct" },
	{ PXENV_STATUS_LOADER_UNDI_START, "Loader UNDI start" },
	{ PXENV_STATUS_LOADER_BC_START, "Loader Base Code start" },
};
