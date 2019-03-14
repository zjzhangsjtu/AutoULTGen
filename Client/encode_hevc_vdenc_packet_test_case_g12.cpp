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
//! \file     encode_hevc_vdenc_packet_g12.cpp
//! \brief    implementation file of EncodeHevcVdencPacketTestCaseG12 class
//! \details  ULT of encode_hevc_vdenc_packet_g12
//!


#include "encode_hevc_vdenc_packet_test_case_g12.h"
#include "gtest/gtest.h"

namespace encode
{

    void EncodeHevcVdencPacketTestCaseG12::SetUp()
    {


    }

    void EncodeHevcVdencPacketTestCaseG12::TearDown()
    {


    }
    void EncodeHevcVdencPacketTestCaseG12::GetPlatformByName(PLATFORM &platform)
    {


    }
    void EncodeHevcVdencPacketTestCaseG12::PrepareEncodeParams(EncoderParams &encodeParams)
    {


    }


    TEST_F(EncodeHevcVdencPacketTestCaseG12, SetHcpPicStateParams)
    {
        EXPECT_EQ(m_packet->SetHcpPicStateParamsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddVdencCmd1Cmd)
    {
        EXPECT_EQ(m_packet->AddVdencCmd1CmdTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddVdencCmd2Cmd)
    {
        EXPECT_EQ(m_packet->AddVdencCmd2CmdTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, PatchSliceLevelCommands)
    {
        EXPECT_EQ(m_packet->PatchSliceLevelCommandsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, PatchTileLevelCommands)
    {
        EXPECT_EQ(m_packet->PatchTileLevelCommandsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddOneTileCommands)
    {
        EXPECT_EQ(m_packet->AddOneTileCommandsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddSlicesCommandsInTile)
    {
        EXPECT_EQ(m_packet->AddSlicesCommandsInTileTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, UpdateParameters)
    {
        EXPECT_EQ(m_packet->UpdateParametersTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddPicStateWithNoTile)
    {
        EXPECT_EQ(m_packet->AddPicStateWithNoTileTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddPicStateWithTile)
    {
        EXPECT_EQ(m_packet->AddPicStateWithTileTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddHcpPipeBufAddrCmd)
    {
        EXPECT_EQ(m_packet->AddHcpPipeBufAddrCmdTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddPictureHcpCommands)
    {
        EXPECT_EQ(m_packet->AddPictureHcpCommandsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddVdencWalkerStateCmd)
    {
        EXPECT_EQ(m_packet->AddVdencWalkerStateCmdTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, SetHcpPipeBufAddrParams)
    {
        EXPECT_EQ(m_packet->SetHcpPipeBufAddrParamsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, AddPictureVdencCommands)
    {
        EXPECT_EQ(m_packet->AddPictureVdencCommandsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, SetVdencPipeBufAddrParams)
    {
        EXPECT_EQ(m_packet->SetVdencPipeBufAddrParamsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, PatchPictureLevelCommands)
    {
        EXPECT_EQ(m_packet->PatchPictureLevelCommandsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, InsertSeqStreamEnd)
    {
        EXPECT_EQ(m_packet->InsertSeqStreamEndTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, EnsureAllCommandsExecuted)
    {
        EXPECT_EQ(m_packet->EnsureAllCommandsExecutedTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, SetVdencPipeModeSelectParams)
    {
        EXPECT_EQ(m_packet->SetVdencPipeModeSelectParamsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, SetHcpSliceStateCommonParams)
    {
        EXPECT_EQ(m_packet->SetHcpSliceStateCommonParamsTest(), MOS_STATUS_SUCCESS);
    }
    TEST_F(EncodeHevcVdencPacketTestCaseG12, Construct3rdLevelBatch)
    {
        EXPECT_EQ(m_packet->Construct3rdLevelBatchTest(), MOS_STATUS_SUCCESS);
    }
}
