/*
 * Copyright (C) Ambroz Bizjak <ambrop7@gmail.com>
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*_t2s_log_func)(int channel, int level, const char *msg);
typedef void (*_t2s_free_func)(void);

// name of the program
#define PROGRAM_NAME "tun2socks"

// size of temporary buffer for passing data from the SOCKS server to TCP for sending
#define CLIENT_SOCKS_RECV_BUF_SIZE 8192

// maximum number of udpgw connections
#define DEFAULT_UDPGW_MAX_CONNECTIONS 256

// udpgw per-connection send buffer size, in number of packets
#define DEFAULT_UDPGW_CONNECTION_BUFFER_SIZE 8

// udpgw reconnect time after connection fails
#define UDPGW_RECONNECT_TIME 5000

// udpgw keepalive sending interval
#define UDPGW_KEEPALIVE_TIME 15000

// option to override the destination addresses to give the SOCKS server
//#define OVERRIDE_DEST_ADDR "10.111.0.2:2000"

// Max number of buffered outgoing UDP packets for SOCKS5-UDP. It should be large
// enough to prevent packet loss while the SOCKS UDP association is being set up. A slow
// or far-away SOCKS server could require 300 ms to connect, and a chatty client (e.g.
// STUN) could send a packet every 20 ms, so a default limit of 16 seems reasonable.
#define SOCKS_UDP_SEND_BUFFER_PACKETS 16

void t2s_log_init(_t2s_log_func log_func, _t2s_free_func free_func);
int t2s_execute(int argc, char **argv);
void t2s_terminate(void);

#ifdef __cplusplus
}
#endif