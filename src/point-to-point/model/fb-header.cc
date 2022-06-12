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

#include <stdint.h>
#include <iostream>
#include "fb-header.h"
#include "ns3/buffer.h"
#include "ns3/address-utils.h"
#include "ns3/log.h"

NS_LOG_COMPONENT_DEFINE("FbHeader");

namespace ns3 {

	NS_OBJECT_ENSURE_REGISTERED(FbHeader);

	FbHeader::FbHeader(uint8_t qindex, uint32_t fid, uint64_t ts, uint32_t qlen, uint32_t qvar)
		: m_qindex(qindex), m_fid(fid), m_ts(ts), m_qlen(qlen), m_qvar(qvar)
	{
	}

	FbHeader::FbHeader()
		: m_qindex(0), m_fid(0), m_ts(0), m_qlen(0), m_qvar(0)
	{}

	FbHeader::~FbHeader()
	{}

	void FbHeader::SetQLen(uint32_t qlen)
	{
		m_qlen = qlen;
	}

	uint32_t FbHeader::GetQLen() const
	{
		return m_qlen;
	}

	void FbHeader::SetQVar(uint32_t qvar)
	{
		m_qvar = qvar;
	}

	uint32_t FbHeader::GetQVar() const
	{
		return m_qvar;
	}

	void FbHeader::SetQIndex(uint8_t qindex)
	{
		m_qindex = qindex;
	}

	uint8_t FbHeader::GetQIndex() const
	{
		return m_qindex;
	}

	void FbHeader::SetFId(uint32_t fid)
	{
		m_fid = fid;
	}

	uint32_t FbHeader::GetFId() const
	{
		return m_fid;
	}

	void FbHeader::SetTs(uint64_t ts)
	{
		m_ts = ts;
	}

	uint64_t FbHeader::GetTs() const
	{
		return m_ts;
	}

	TypeId
		FbHeader::GetTypeId(void)
	{
		static TypeId tid = TypeId("ns3::FbHeader")
			.SetParent<Header>()
			.AddConstructor<FbHeader>()
			;
		return tid;
	}
	TypeId
		FbHeader::GetInstanceTypeId(void) const
	{
		return GetTypeId();
	}

	void FbHeader::Print(std::ostream &os) const
	{
		os << "Fb: qindex=" << m_qindex << ", fid=" << m_fid << ", ts=" << m_ts << ", qlen = " << m_qlen << ", qvar = " << m_qvar;
	}

	uint32_t FbHeader::GetSerializedSize(void)  const
	{
		return 21;
	}

	void FbHeader::Serialize(Buffer::Iterator start)  const
	{
		start.WriteU8(m_qindex);
		start.WriteU32(m_fid);
		start.WriteU64(m_ts);
		start.WriteU32(m_qlen);
		start.WriteU32(m_qvar);
	}

	uint32_t FbHeader::Deserialize(Buffer::Iterator start)
	{
		m_qindex = start.ReadU8();
		m_fid = start.ReadU32();
		m_ts = start.ReadU64();
		m_qlen = start.ReadU32();
		m_qvar = start.ReadU32();
		return GetSerializedSize();
	}


}; // namespace ns3
