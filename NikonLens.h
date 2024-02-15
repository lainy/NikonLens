/*
 * NikonLens.h
 *
 *  Created: 11/14/2013 02:46:07
 *
 *  Lain A.
 *  code@hacktheinter.net
 *  http://hacktheinter.net
 *
 *  Copyright (c) 2013 Lain A.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#ifndef NIKONLENS_H_
#define NIKONLENS_H_

#include <numeric.h>

namespace lain {

//! Control Nikon F-mount lenses from an Arduino
/*! Nikon lenses use a modified version of SPI.
 * See also:
 *  -    Protocol: https://web.archive.org/web/20230323004623/http://nikonhacker.com/wiki/Lens_Serial_Interface
 *  -      Pinout: https://web.archive.org/web/20230323004623/http://nikonhacker.com/wiki/F-Mount
 *  - Arduino SPI: http://arduino.cc/en/Reference/SPI
 * 
 * Connections are as follows (with Arduino Uno pin numbers):
 *  - SS   (10) is unused.
 *  - SCK  (13) is connected directly to lens SCLK.
 *  - MISO (12) is connected to the lens Data line, which must be pulled high.
 *  - MOSI (11) drives the lens Data line through a transistor, open-collector.\n
 *    So: MOSI -> Base, Data -> Collector, GND -> Emitter
 *  - handshakePin_In  is connected directly to lens H/S
 *  - handshakePin_Out drives lens H/S through a transistor, open-collector.
 *
 * NOTE: The Nikon D5100 starts communication with the lens at 96kHz, then
 *       increases speed to 156kHz if the lens supports it. Because the
 *       Arduino runs at 16MHz and the maximum divider ratio for SPI is
 *       128, the slowest we can run the bus is 125kHz.\n
 *       If using this code with older lenses causes problems, it should
 *       be modified to use the AVR's System Clock Prescaler to drop the CPU
 *       frequency so you can achieve a slower SPI bus speed.\n
 *       I haven't tested this, it may interfere with other Arduino features.
 */
class tNikonLens
{
public:
	//! Possible result codes for commands
	enum tResultCode {
		Success,
		Timeout
	};
	
	//! Initialize SPI for lens communication.
	/*! See class description for connection information.
	 \param[in]  handshakePin_In  Input pin for reading the H/S line.
	 \param[in]  handshakePin_Out Output pin for pulling the H/S line low.
	 */
	void begin(
		u8 handshakePin_In,
		u8 handshakePin_Out
		);
	//! Tear down, relinquish resources.
	void end();
	
	//todo: functions to send basic commands with more understandable arguments
	// like tResultCode DoAutoFocus(u8 unknown, tDirection dir, u16 steps);
	
	//! Send lens command and read/write data.
	/*! Sends command \a cmd to the lens.\n
	 If data is to be received, \a byteCountFromLens must be set
	 to the number of bytes expected.\n If data is to be sent,
	 \a byteCountToLens must be set to the number of bytes to send.\n
	 Received data is placed in \a bytesFromLens, so it must be sized
	 accordingly.\n Likewise, data sent to the lens is sourced from
	 \a bytesToLens.
	 
	 \param[in]  cmd				The command byte to send.
	 \param[in]  byteCountFromLens	Number of bytes to receive, or zero if not receiving.
	 \param[out] bytesFromLens		Destination for received bytes, or null if not receiving.
	 \param[in]  byteCountToLens    Number of bytes to send, or zero if not sending.
	 \param[in]  bytesToLens		Source of bytes sent to lens, or null if not sending.
	 \returns A result code indicating success, or the failure cause.
	 */
	tResultCode sendCommand(
		u8  cmd,
		u8  byteCountFromLens = 0,
		u8* bytesFromLens = nullptr,
		u8  byteCountToLens = 0,
		u8 const* bytesToLens = nullptr
		);
	
private:
	u8 m_handshakePin_In;
	u8 m_handshakePin_Out;
	
	//! Assert (pull down) the H/S line for \a microseconds.
	/*! \note This will block for the duration. */
	void assertHandshake(u16 microseconds);
	//! Shortcut to read handshake value
	/*! \returns \c true if H/S is asserted (low), \c false otherwise. */
	bool isHandshakeAsserted() const { return 0 == digitalRead(m_handshakePin_In); }
};

// Global instance, because I'm a terrible person
extern tNikonLens NikonLens;

}	/* namespace lain */

#endif /* NIKONLENS_H_ */

// eof
