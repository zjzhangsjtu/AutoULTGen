test_encode_hevc_vdenc_packet_g12.h/*===================== begin_copyright_notice ==================================

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
//! \brief    implementation file of TestHevcVdencPktG12 class
//! \a mock derived from test_encode_hevc_vdenc_packet_g12 and used for ult test
//!


namespace encode
{
        MOS_STATUS TestHevcVdencPktG12::SubmitTest()
        {
            MOS_COMMAND_BUFFER *commandBuffer;
            memset(&*commandBuffer, 0, sizeof(*commandBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::Submit(*commandBuffer), MOS_STATUS_SUCCESS);

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

            EXPECT_EQ(TestHevcVdencPktG12::AddVdencCmd1Cmd(cmdBuffer, addToBatchBufferHuCBRC, isLowDelayB), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencCmd2CmdTest()
        {
            PMOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            bool addToBatchBufferHuCBRC = 0;

            bool isLowDelayB = 0;

            EXPECT_EQ(TestHevcVdencPktG12::AddVdencCmd2Cmd(cmdBuffer, addToBatchBufferHuCBRC, isLowDelayB), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CalculatePictureStateCommandSizeTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::CalculatePictureStateCommandSize(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::PatchSliceLevelCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            uint8_t packetPhase = 0;

            EXPECT_EQ(TestHevcVdencPktG12::PatchSliceLevelCommands(cmdBuffer, packetPhase), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::PatchTileLevelCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            uint8_t packetPhase = 0;

            EXPECT_EQ(TestHevcVdencPktG12::PatchTileLevelCommands(cmdBuffer, packetPhase), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddOneTileCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            uint32_t tileRow = 0;

            uint32_t tileCol = 0;

            uint32_t tileRowPass = 0;

            EXPECT_EQ(TestHevcVdencPktG12::AddOneTileCommands(cmdBuffer, tileRow, tileCol, tileRowPass), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddSlicesCommandsInTileTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddSlicesCommandsInTile(cmdBuffer), MOS_STATUS_SUCCESS);

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

            EXPECT_EQ(TestHevcVdencPktG12::AddPicStateWithNoTile(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddPicStateWithTileTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddPicStateWithTile(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPipeBufAddrCmdTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpPipeBufAddrCmd(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddPictureHcpCommandsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddPictureHcpCommands(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencWalkerStateCmdTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE params;
            memset(&params, 0, sizeof(params));

            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddVdencWalkerStateCmd(params, cmdBuffer), MOS_STATUS_SUCCESS);

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

            EXPECT_EQ(TestHevcVdencPktG12::AddPictureVdencCommands(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencPipeBufAddrParamsTest()
        {
            MHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams;
            memset(&pipeBufAddrParams, 0, sizeof(pipeBufAddrParams));

            EXPECT_EQ(TestHevcVdencPktG12::SetVdencPipeBufAddrParams(pipeBufAddrParams), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::PatchPictureLevelCommandsTest()
        {
            uint8_t packetPhase = 0;

            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::PatchPictureLevelCommands(packetPhase, cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::InsertSeqStreamEndTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::InsertSeqStreamEnd(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::EnsureAllCommandsExecutedTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::EnsureAllCommandsExecuted(cmdBuffer), MOS_STATUS_SUCCESS);

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

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpRefIdxCmd(cmdBuffer, batchBuffer, params), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPipeModeSelectTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpPipeModeSelect(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpSurfacesTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpSurfaces(cmdBuffer), MOS_STATUS_SUCCESS);

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

            EXPECT_EQ(TestHevcVdencPktG12::SetHcpSliceStateParams(sliceStateParams, slcData, currSlcIdx), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::Construct3rdLevelBatchTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::Construct3rdLevelBatch(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AllocateResourcesTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::AllocateResources(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::= hwInterface->GetOsInterfaceTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::= hwInterface->GetOsInterface(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::= hwInterface->GetMiInterfaceTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::= hwInterface->GetMiInterface(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::= m_pipeline->GetStatusReportInstanceTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::= m_pipeline->GetStatusReportInstance(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::= hwInterface->GetHcpInterfaceTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::= hwInterface->GetHcpInterface(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::= hwInterface->GetVdencInterfaceTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::= hwInterface->GetVdencInterface(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::= m_pipeline->GetFeatureManagerTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::= m_pipeline->GetFeatureManager(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::~HevcVdencPktTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::~HevcVdencPkt(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::InitTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::Init(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::PrepareTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::Prepare(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::DestoryTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::Destory(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SubmitTest()
        {
            MOS_COMMAND_BUFFER *commandBuffer;
            memset(&*commandBuffer, 0, sizeof(*commandBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::Submit(*commandBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CompletedTest()
        {
            void *mfxStatus;
            memset(&*mfxStatus, 0, sizeof(*mfxStatus));

            void *rcsStatus;
            memset(&*rcsStatus, 0, sizeof(*rcsStatus));

            void *statusReport;
            memset(&*statusReport, 0, sizeof(*statusReport));

            EXPECT_EQ(TestHevcVdencPktG12::Completed(*mfxStatus, *rcsStatus, *statusReport), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CalculatePictureStateCommandSizeTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::CalculatePictureStateCommandSize(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::GetVdencStateCommandsDataSizeTest()
        {
            uint32_t vdencPictureStatesSize = 0;

            uint32_t vdencPicturePatchListSize = 0;

            EXPECT_EQ(TestHevcVdencPktG12::GetVdencStateCommandsDataSize(vdencPictureStatesSize, vdencPicturePatchListSize), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CalculateCommandSizeTest()
        {
            uint32_t commandBufferSize = 0;

            uint32_t requestedPatchListSize = 0;

            EXPECT_EQ(TestHevcVdencPktG12::CalculateCommandSize(commandBufferSize, requestedPatchListSize), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::GetPacketNameTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::GetPacketName(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::GetHxxPrimitiveCommandSizeTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::GetHxxPrimitiveCommandSize(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CalculateCommandBufferSizeTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::CalculateCommandBufferSize(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CalculatePatchListSizeTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::CalculatePatchListSize(), 0);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::EndStatusReportTest()
        {
            uint32_t srType = 0;

            MOS_COMMAND_BUFFER *cmdBuffer;
            memset(&*cmdBuffer, 0, sizeof(*cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::EndStatusReport(srType, *cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::ReadHcpStatusTest()
        {
            MHW_VDBOX_NODE_IND vdboxIndex;
            memset(&vdboxIndex, 0, sizeof(vdboxIndex));

            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::ReadHcpStatus(vdboxIndex, cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AllocateResourcesTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::AllocateResources(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetPakPassTypeTest()
        {

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpSrcSurfaceParamsTest()
        {
            MHW_VDBOX_SURFACE_PARAMS srcSurfaceParams;
            memset(&srcSurfaceParams, 0, sizeof(srcSurfaceParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpReconSurfaceParamsTest()
        {
            MHW_VDBOX_SURFACE_PARAMS reconSurfaceParams;
            memset(&reconSurfaceParams, 0, sizeof(reconSurfaceParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPipeBufAddrCmdTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpPipeBufAddrCmd(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpIndObjBaseAddrCmdTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpIndObjBaseAddrCmd(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpIndObjBaseAddrParamsTest()
        {
            MHW_VDBOX_IND_OBJ_BASE_ADDR_PARAMS indObjBaseAddrParams;
            memset(&indObjBaseAddrParams, 0, sizeof(indObjBaseAddrParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpQmStateCmdTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpQmStateCmd(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpQmStateParamsTest()
        {
            MHW_VDBOX_QM_PARAMS fqmParams;
            memset(&fqmParams, 0, sizeof(fqmParams));

            MHW_VDBOX_QM_PARAMS qmParams;
            memset(&qmParams, 0, sizeof(qmParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencSurfaceStateParamsTest()
        {
            MHW_VDBOX_SURFACE_PARAMS srcSurfaceParams;
            memset(&srcSurfaceParams, 0, sizeof(srcSurfaceParams));

            MHW_VDBOX_SURFACE_PARAMS reconSurfaceParams;
            memset(&reconSurfaceParams, 0, sizeof(reconSurfaceParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencDSSurfaceStateParamsTest()
        {
            MHW_VDBOX_SURFACE_PARAMS ds8xSurfaceParams;
            memset(&ds8xSurfaceParams, 0, sizeof(ds8xSurfaceParams));

            MHW_VDBOX_SURFACE_PARAMS ds4xSurfaceParams;
            memset(&ds4xSurfaceParams, 0, sizeof(ds4xSurfaceParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddPicStateWithNoTileTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddPicStateWithNoTile(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SendHwSliceEncodeCommandTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE params;
            memset(&params, 0, sizeof(params));

            EXPECT_EQ(TestHevcVdencPktG12::SendHwSliceEncodeCommand(params), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencDsRefSurfaceStateParamsTest()
        {
            PMOS_SURFACE ds8xSurface;
            memset(&ds8xSurface, 0, sizeof(ds8xSurface));

            PMOS_SURFACE ds4xSurface;
            memset(&ds4xSurface, 0, sizeof(ds4xSurface));

            CODECHAL_MODE mode;
            memset(&mode, 0, sizeof(mode));

            MHW_VDBOX_SURFACE_PARAMS ds8xSurfaceParams;
            memset(&ds8xSurfaceParams, 0, sizeof(ds8xSurfaceParams));

            MHW_VDBOX_SURFACE_PARAMS ds4xSurfaceParams;
            memset(&ds4xSurfaceParams, 0, sizeof(ds4xSurfaceParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::VdencPipeModeSelectTest()
        {
            MHW_VDBOX_PIPE_MODE_SELECT_PARAMS pipeModeSelectParams;
            memset(&pipeModeSelectParams, 0, sizeof(pipeModeSelectParams));

            EXPECT_EQ(TestHevcVdencPktG12::VdencPipeModeSelect(pipeModeSelectParams), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencSurfacesTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::SetVdencSurfaces(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencPipeBufAddrCmdTest()
        {
            MHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams;
            memset(&pipeBufAddrParams, 0, sizeof(pipeBufAddrParams));

            EXPECT_EQ(TestHevcVdencPktG12::AddVdencPipeBufAddrCmd(pipeBufAddrParams), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::ReadSliceSizeForSinglePipeTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::ReadSliceSizeForSinglePipe(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::ReadSliceSizeTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::ReadSliceSize(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CopyDataBlockTest()
        {
            PMOS_RESOURCE sourceSurface;
            memset(&sourceSurface, 0, sizeof(sourceSurface));

            uint32_t sourceOffset = 0;

            PMOS_RESOURCE destSurface;
            memset(&destSurface, 0, sizeof(destSurface));

            uint32_t destOffset = 0;

            uint32_t copySize = 0;

            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::CopyDataBlock(sourceSurface, sourceOffset, destSurface, destOffset, copySize, cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::WaitHevcDoneTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::WaitHevcDone(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::WaitVdencDoneTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::WaitVdencDone(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::WaitHevcVdencDoneTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::WaitHevcVdencDone(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpPipeModeSelectParamsTest()
        {
            MHW_VDBOX_PIPE_MODE_SELECT_PARAMS vdboxPipeModeSelectParams;
            memset(&vdboxPipeModeSelectParams, 0, sizeof(vdboxPipeModeSelectParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPipeModeSelectTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpPipeModeSelect(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpSurfacesTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpSurfaces(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpPipeBufAddrParamsTest()
        {
            MHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams;
            memset(&pipeBufAddrParams, 0, sizeof(pipeBufAddrParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencPipeModeSelectParamsTest()
        {
            MHW_VDBOX_PIPE_MODE_SELECT_PARAMS vdboxPipeModeSelectParams;
            memset(&vdboxPipeModeSelectParams, 0, sizeof(vdboxPipeModeSelectParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetVdencPipeBufAddrParamsTest()
        {
            MHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams;
            memset(&pipeBufAddrParams, 0, sizeof(pipeBufAddrParams));

            EXPECT_EQ(TestHevcVdencPktG12::SetVdencPipeBufAddrParams(pipeBufAddrParams), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpPicStateParamsTest()
        {
            MHW_VDBOX_HEVC_PIC_STATE picStateParams;
            memset(&picStateParams, 0, sizeof(picStateParams));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpWeightOffsetStateCmdTest()
        {
            CODEC_HEVC_ENCODE_SLICE_PARAMS hevcSlcParams;
            memset(&hevcSlcParams, 0, sizeof(hevcSlcParams));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpWeightOffsetStateCmd(hevcSlcParams), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpHevcVp9RdoqStateCmdTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            PMHW_VDBOX_HEVC_PIC_STATE params;
            memset(&params, 0, sizeof(params));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpHevcVp9RdoqStateCmd(cmdBuffer, params), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPakInsertSliceHeaderTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE params;
            memset(&params, 0, sizeof(params));

            PMHW_BATCH_BUFFER batchBuffer;
            memset(&batchBuffer, 0, sizeof(batchBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpPakInsertSliceHeader(params, batchBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencWeightOffsetStateCmdTest()
        {
            CODEC_HEVC_ENCODE_SLICE_PARAMS hevcSlcParams;
            memset(&hevcSlcParams, 0, sizeof(hevcSlcParams));

            EXPECT_EQ(TestHevcVdencPktG12::AddVdencWeightOffsetStateCmd(hevcSlcParams), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddVdencWalkerStateCmdTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE params;
            memset(&params, 0, sizeof(params));

            EXPECT_EQ(TestHevcVdencPktG12::AddVdencWalkerStateCmd(params), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::ValidateVdboxIdxTest()
        {
            MHW_VDBOX_NODE_IND vdboxIndex;
            memset(&vdboxIndex, 0, sizeof(vdboxIndex));

            EXPECT_EQ(TestHevcVdencPktG12::ValidateVdboxIdx(vdboxIndex), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetPerfTagTest()
        {
            uint16_t type = 0;

            uint16_t mode = 0;

            uint16_t picCodingType = 0;


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetHcpSliceStateParamsTest()
        {
            MHW_VDBOX_HEVC_SLICE_STATE sliceStateParams;
            memset(&sliceStateParams, 0, sizeof(sliceStateParams));

            PCODEC_ENCODER_SLCDATA slcData;
            memset(&slcData, 0, sizeof(slcData));

            uint32_t currSlcIdx = 0;

            EXPECT_EQ(TestHevcVdencPktG12::SetHcpSliceStateParams(sliceStateParams, slcData, currSlcIdx), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetSemaphoreMemTest()
        {
            uint32_t value = 0;

            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::SetSemaphoreMem(value, cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SendPrologCmdsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::SendPrologCmds(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AllocateBatchBufferForPakSlicesTest()
        {
            uint32_t numSlices = 0;

            uint8_t numPakPasses = 0;

            EXPECT_EQ(TestHevcVdencPktG12::AllocateBatchBufferForPakSlices(numSlices, numPakPasses), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetBatchBufferForPakSlicesTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::SetBatchBufferForPakSlices(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::ReadSseStatisticsTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::ReadSseStatistics(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddForceWakeupTest()
        {
            MOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            EXPECT_EQ(TestHevcVdencPktG12::AddForceWakeup(cmdBuffer), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::AddHcpPakInsertNALUsTest()
        {
            PMOS_COMMAND_BUFFER cmdBuffer;
            memset(&cmdBuffer, 0, sizeof(cmdBuffer));

            PMHW_BATCH_BUFFER batchBuffer;
            memset(&batchBuffer, 0, sizeof(batchBuffer));

            PMHW_VDBOX_HEVC_SLICE_STATE params;
            memset(&params, 0, sizeof(params));

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpPakInsertNALUs(cmdBuffer, batchBuffer, params), MOS_STATUS_SUCCESS);

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

            EXPECT_EQ(TestHevcVdencPktG12::AddHcpRefIdxCmd(cmdBuffer, batchBuffer, params), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::CalculatePSNRTest()
        {
            EncodeStatusReportData *statusReportData;
            memset(&*statusReportData, 0, sizeof(*statusReportData));

            EXPECT_EQ(TestHevcVdencPktG12::CalculatePSNR(*statusReportData), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::SetRowstoreCachingOffsetsTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::SetRowstoreCachingOffsets(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::FreeResourcesTest()
        {
            EXPECT_EQ(TestHevcVdencPktG12::FreeResources(), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestHevcVdencPktG12::DumpResourcesTest()
        {
            EncodeStatusMfx *encodeStatusMfx;
            memset(&*encodeStatusMfx, 0, sizeof(*encodeStatusMfx));

            EncodeStatusReportData *statusReportData;
            memset(&*statusReportData, 0, sizeof(*statusReportData));

            EXPECT_EQ(TestHevcVdencPktG12::DumpResources(*encodeStatusMfx, *statusReportData), MOS_STATUS_SUCCESS);

            return MOS_STATUS_SUCCESS;
        }

}
