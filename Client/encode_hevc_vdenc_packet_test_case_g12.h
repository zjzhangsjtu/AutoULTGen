/*===================== begin_copyright_notice ==================================

INTEL CONFIDENTIAL
Copyright 2018
Intel Corporation All Rights Reserved.

The source code contained or described herein and all documents related to the
source code ("Material") are owned by Intel Corporation or its suppliers or
licensors. Title to the Material remains with Intel Corporation or its suppliers
and licensors. The Material contains trade secrets and proprietary and confidential
information of Intel or its suppliers and licensors. The Material is protected by
worldwide copyright and trade secret laws and treaty provisions. No part of the
Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express
written permission.

No license under any patent, copyright, trade secret or other intellectual
property right is granted to or conferred upon you by disclosure or delivery
of the Materials, either expressly, by implication, inducement, estoppel
or otherwise. Any license under such intellectual property rights must be
express and approved by Intel in writing.

======================= end_copyright_notice ==================================*/

//!
//! \file     encode_hevc_vdenc_packet_test_case_g12.h
//! \brief    header file of EncodeHevcVdencPacketTestCaseG12 class
//! \details
//!

#ifndef __ENCODE_HEVC_VDENC_PACKET_TEST_CASE_G12_H__
#define __ENCODE_HEVC_VDENC_PACKET_TEST_CASE_G12_H__

#include "memory_leak_detector.h"
#include "mock_platform.h"
#include "test_encode_hevc_vdenc_packet_g12.h"
#include "encode_test_fixture.h"

namespace encode
{
    class EncodeHevcVdencPacketTestCaseG12 : public EncodeTestFixture
    {

    protected:


        //!
        //! \brief   Initialization work before executing a unit test
        //!
        virtual void SetUp();

        //!
        //! \brief   Uninitializaiton and exception handling after the unit test done
        //!
        virtual void TearDown();

        //!
        //! \brief   Get Platform
        //! \param   [in] platform
        //! \        Reference to PLATFORM
        //!
        void GetPlatformByName(PLATFORM &platform);

        //!
        //! \brief   Prepare Encode Params
        //! \param   [in] encodeParams
        //! \        Reference to EncodeParams
        //!
        void PrepareEncodeParams(EncoderParams &encodeParams);

        TestHevcVdencPktG12        *m_packet = nullptr;

    };
}

#endif
