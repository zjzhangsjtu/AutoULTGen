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
//! \file     test_encode_hevc_vdenc_packet_g12.cpp
//! \brief    implementation file of HevcVdencPktG12 class
//! \a mock derived from test_encode_hevc_vdenc_packet and used for ult test
//!


#include "test_encode_hevc_vdenc_packet_g12.h"
#include "gtest/gtest.h"

namespace encode
{
        MOS_STATUS TestHevcVdencPktG12::PrepareTest()
        {
            EXPECT_EQ(HevcVdencPktG12::Prepare(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SubmitTest()
        {
            MOS_COMMAND_BUFFER* commandBuffer;
            memset(&commandBuffer, 0, sizeof(commandBuffer));

            EXPECT_EQ(HevcVdencPktG12::Submit(commandBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpPicStateParamsTest()
        {
            MHW_VDBOX_HEVC_PIC_STATE picStateParams;
            memset(&picStateParams, 0, sizeof(picStateParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencCmd1CmdTest()
        {
            PMOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            bool addToBatchBufferHuCBRC = 0;

            bool isLowDelayB = 0;

            EXPECT_EQ(HevcVdencPktG12::AddVdencCmd1Cmd(cmdBuffer, addToBatchBufferHuCBRC, isLowDelayB), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencCmd2CmdTest()
        {
            PMOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            bool addToBatchBufferHuCBRC = 0;

            bool isLowDelayB = 0;

            EXPECT_EQ(HevcVdencPktG12::AddVdencCmd2Cmd(cmdBuffer, addToBatchBufferHuCBRC, isLowDelayB), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CalculatePictureStateCommandSizeTest()
        {
            EXPECT_EQ(HevcVdencPktG12::CalculatePictureStateCommandSize(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::PatchSliceLevelCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            uint8_t packetPhase = 0;

            EXPECT_EQ(HevcVdencPktG12::PatchSliceLevelCommands(cmdBuffer, packetPhase), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::PatchTileLevelCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            uint8_t packetPhase = 0;

            EXPECT_EQ(HevcVdencPktG12::PatchTileLevelCommands(cmdBuffer, packetPhase), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddOneTileCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            uint32_t tileRow = 0;

            uint32_t tileCol = 0;

            uint32_t tileRowPass = 0;

            EXPECT_EQ(HevcVdencPktG12::AddOneTileCommands(cmdBuffer, tileRow, tileCol, tileRowPass), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddSlicesCommandsInTileTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddSlicesCommandsInTile(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::UpdateParametersTest()
        {

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddPicStateWithNoTileTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddPicStateWithNoTile(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddPicStateWithTileTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddPicStateWithTile(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPipeBufAddrCmdTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddHcpPipeBufAddrCmd(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddPictureHcpCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddPictureHcpCommands(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencWalkerStateCmdTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE params;
            memset(&params, 0, sizeof(params));

            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddVdencWalkerStateCmd(params, cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpPipeBufAddrParamsTest()
        {
            MHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams;
            memset(&pipeBufAddrParams, 0, sizeof(pipeBufAddrParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddPictureVdencCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddPictureVdencCommands(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencPipeBufAddrParamsTest()
        {
            MHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams;
            memset(&pipeBufAddrParams, 0, sizeof(pipeBufAddrParams));

            EXPECT_EQ(HevcVdencPktG12::SetVdencPipeBufAddrParams(pipeBufAddrParams), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::PatchPictureLevelCommandsTest()
        {
            uint8_t packetPhase = 0;

            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::PatchPictureLevelCommands(packetPhase, cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::InsertSeqStreamEndTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::InsertSeqStreamEnd(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::EnsureAllCommandsExecutedTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::EnsureAllCommandsExecuted(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpPipeModeSelectParamsTest()
        {
            MHW_VDBOX_PIPE_MODE_SELECT_PARAMS vdboxPipeModeSelectParams;
            memset(&vdboxPipeModeSelectParams, 0, sizeof(vdboxPipeModeSelectParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpRefIdxCmdTest()
        {
            PMOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            PMHW_BATCH_BUFFER batchBuffer;
            memset(&batchBuffer, 0, sizeof(batchBuffer));

            PMHW_VDBOX_HEVC_SLICE_STATE params;
            memset(&params, 0, sizeof(params));

            EXPECT_EQ(HevcVdencPktG12::AddHcpRefIdxCmd(cmdBuffer, batchBuffer, params), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPipeModeSelectTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddHcpPipeModeSelect(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpSurfacesTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(HevcVdencPktG12::AddHcpSurfaces(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencPipeModeSelectParamsTest()
        {
            MHW_VDBOX_PIPE_MODE_SELECT_PARAMS vdboxPipeModeSelectParams;
            memset(&vdboxPipeModeSelectParams, 0, sizeof(vdboxPipeModeSelectParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpSliceStateCommonParamsTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE sliceStateParams;
            memset(&sliceStateParams, 0, sizeof(sliceStateParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpSliceStateParamsTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE sliceStateParams;
            memset(&sliceStateParams, 0, sizeof(sliceStateParams));

            PCODEC_ENCODER_SLCDATA slcData;
            memset(&slcData, 0, sizeof(slcData));

            uint32_t currSlcIdx = 0;

            EXPECT_EQ(HevcVdencPktG12::SetHcpSliceStateParams(sliceStateParams, slcData, currSlcIdx), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::Construct3rdLevelBatchTest()
        {
            EXPECT_EQ(HevcVdencPktG12::Construct3rdLevelBatch(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AllocateResourcesTest()
        {
            EXPECT_EQ(HevcVdencPktG12::AllocateResources(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

}
