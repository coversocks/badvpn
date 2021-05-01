
set(BADVPN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(tun2socks_DEFS -D__APPLE_USE_RFC_3542 -DBADVPN_THREAD_SAFE=0 -DBADVPN_LINUX -DBADVPN_BREACTOR_BADVPN -D_GNU_SOURCE -DBADVPN_USE_EPOLL -DBADVPN_USE_SIGNALFD -DBADVPN_LITTLE_ENDIAN -DUDPGW_EMBED)
set(tun2socks_INCLUDES
        "${BADVPN_DIR}"
        "${BADVPN_DIR}/lwip/src/include/ipv4"
        "${BADVPN_DIR}/lwip/src/include/ipv6"
        "${BADVPN_DIR}/lwip/src/include"
        "${BADVPN_DIR}/lwip/custom"
        )
set(tun2socks_SRCS
        "${BADVPN_DIR}/base/BLog_syslog.c"
        "${BADVPN_DIR}/system/BReactor_badvpn.c"
        "${BADVPN_DIR}/system/BSignal.c"
        "${BADVPN_DIR}/system/BConnection_unix.c"
        "${BADVPN_DIR}/system/BConnection_common.c"
        "${BADVPN_DIR}/system/BTime.c"
        "${BADVPN_DIR}/system/BUnixSignal.c"
        "${BADVPN_DIR}/system/BNetwork.c"
        "${BADVPN_DIR}/system/BDatagram_common.c"
        "${BADVPN_DIR}/system/BDatagram_unix.c"
        "${BADVPN_DIR}/flow/StreamRecvInterface.c"
        "${BADVPN_DIR}/flow/PacketRecvInterface.c"
        "${BADVPN_DIR}/flow/PacketPassInterface.c"
        "${BADVPN_DIR}/flow/StreamPassInterface.c"
        "${BADVPN_DIR}/flow/SinglePacketBuffer.c"
        "${BADVPN_DIR}/flow/BufferWriter.c"
        "${BADVPN_DIR}/flow/PacketBuffer.c"
        "${BADVPN_DIR}/flow/PacketStreamSender.c"
        "${BADVPN_DIR}/flow/PacketPassConnector.c"
        "${BADVPN_DIR}/flow/PacketProtoFlow.c"
        "${BADVPN_DIR}/flow/PacketPassFairQueue.c"
        "${BADVPN_DIR}/flow/PacketProtoEncoder.c"
        "${BADVPN_DIR}/flow/PacketProtoDecoder.c"
        "${BADVPN_DIR}/socksclient/BSocksClient.c"
        "${BADVPN_DIR}/tuntap/BTap.c"
        "${BADVPN_DIR}/lwip/src/core/udp.c"
        "${BADVPN_DIR}/lwip/src/core/memp.c"
        "${BADVPN_DIR}/lwip/src/core/init.c"
        "${BADVPN_DIR}/lwip/src/core/pbuf.c"
        "${BADVPN_DIR}/lwip/src/core/tcp.c"
        "${BADVPN_DIR}/lwip/src/core/tcp_out.c"
        "${BADVPN_DIR}/lwip/src/core/sys.c"
        "${BADVPN_DIR}/lwip/src/core/netif.c"
        "${BADVPN_DIR}/lwip/src/core/def.c"
        "${BADVPN_DIR}/lwip/src/core/mem.c"
        "${BADVPN_DIR}/lwip/src/core/tcp_in.c"
        "${BADVPN_DIR}/lwip/src/core/stats.c"
        "${BADVPN_DIR}/lwip/src/core/ip.c"
        "${BADVPN_DIR}/lwip/src/core/timeouts.c"
        "${BADVPN_DIR}/lwip/src/core/inet_chksum.c"
        "${BADVPN_DIR}/lwip/src/core/ipv4/icmp.c"
        "${BADVPN_DIR}/lwip/src/core/ipv4/ip4.c"
        "${BADVPN_DIR}/lwip/src/core/ipv4/ip4_addr.c"
        "${BADVPN_DIR}/lwip/src/core/ipv4/ip4_frag.c"
        "${BADVPN_DIR}/lwip/src/core/ipv6/ip6.c"
        "${BADVPN_DIR}/lwip/src/core/ipv6/nd6.c"
        "${BADVPN_DIR}/lwip/src/core/ipv6/icmp6.c"
        "${BADVPN_DIR}/lwip/src/core/ipv6/ip6_addr.c"
        "${BADVPN_DIR}/lwip/src/core/ipv6/ip6_frag.c"
        "${BADVPN_DIR}/lwip/custom/sys.c"
        "${BADVPN_DIR}/tun2socks/tun2socks.c"
        "${BADVPN_DIR}/base/DebugObject.c"
        "${BADVPN_DIR}/base/BLog.c"
        "${BADVPN_DIR}/base/BPending.c"
        "${BADVPN_DIR}/flowextra/PacketPassInactivityMonitor.c"
        "${BADVPN_DIR}/tun2socks/SocksUdpGwClient.c"
        "${BADVPN_DIR}/udpgw_client/UdpGwClient.c"
        "${BADVPN_DIR}/socks_udp_client/SocksUdpClient.c"
        )
add_library(tun2socks STATIC ${tun2socks_SRCS})
target_compile_definitions(tun2socks PRIVATE ${tun2socks_DEFS})
target_compile_options(tun2socks PRIVATE -Wno-parentheses -Wno-writable-strings -Wno-reserved-user-defined-literal)
target_include_directories(tun2socks PRIVATE ${tun2socks_INCLUDES})
set_target_properties(tun2socks PROPERTIES PUBLIC_HEADER "${BADVPN_DIR}/tun2socks/tun2socks.h;${BADVPN_DIR}/tun2socks/SocksUdpGwClient.h")

INSTALL (
    DIRECTORY ${BADVPN_DIR}/misc
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/base
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/system
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/flow
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/flowextra
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/udpgw_client
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/udpgw
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/socks_udp_client
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/socksclient
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
INSTALL (
    DIRECTORY ${BADVPN_DIR}/tuntap
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")