/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
* Copyright (c) 2009 New York University
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation;
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
* Author: Adrian S.-W. Tam <adrian.sw.tam@gmail.com>
*/

#ifndef FB_HEADER_H
#define FB_HEADER_H

#include <stdint.h>
#include "ns3/header.h"
#include "ns3/buffer.h"

namespace ns3 {

	/**
	* \ingroup Pause
	* \brief Header for the Congestion Notification Message
	*
	* This class has two fields: The five-tuple flow id and the quantized
	* congestion level. This can be serialized to or deserialzed from a byte
	* buffer.
	*/

	class FbHeader : public Header
	{
	public:
		FbHeader(uint8_t qindex, uint32_t fid, uint64_t ts, uint32_t qlen, uint32_t qvar);
		FbHeader();
		virtual ~FbHeader();

		//Setters

		void SetQIndex(uint8_t qindex);
		void SetFId(uint32_t fid);
		void SetTs(uint64_t ts);
		void SetQLen(uint32_t qlen);
		void SetQVar(uint32_t qvar);

		//Getters

		uint8_t GetQIndex() const;
		uint32_t GetFId() const;
		uint64_t GetTs() const;
		uint32_t GetQLen() const;
		uint32_t GetQVar() const;

		static TypeId GetTypeId(void);
		virtual TypeId GetInstanceTypeId(void) const;
		virtual void Print(std::ostream &os) const;
		virtual uint32_t GetSerializedSize(void) const;
		virtual void Serialize(Buffer::Iterator start) const;
		virtual uint32_t Deserialize(Buffer::Iterator start);

	private:

		uint8_t m_qindex;
		uint32_t m_fid;
		uint64_t m_ts;
		uint32_t m_qlen;
		uint32_t m_qvar;
	};

}; // namespace ns3

#endif /* FB_HEADER */
