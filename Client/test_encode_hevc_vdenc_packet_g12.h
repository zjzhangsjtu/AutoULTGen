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
//! \file     test_encode_hevc_vdenc_packet_g12.h
//! \brief    header file of HevcVdencPktG12 class
//! \details
//!

#ifndef __TEST_ENCODE_HEVC_VDENC_PACKET_G12_H__
#define __TEST_ENCODE_HEVC_VDENC_PACKET_G12_H__

#include "encode_hevc_vdenc_packet_g12.h"

namespace encode
{
    class TestHevcVdencPktG12 : public HevcVdencPktG12
    {

    public:


        virtual ~TestHevcVdencPktG12() {};

        //!
        //! \brief     Test  Prepare
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS PrepareTest();

        //!
        //! \brief     Test  Submit
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SubmitTest();

        //!
        //! \brief     Test  SetHcpPicStateParams
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SetHcpPicStateParamsTest();

        //!
        //! \brief     Test  AddVdencCmd1Cmd
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddVdencCmd1CmdTest();

        //!
        //! \brief     Test  AddVdencCmd2Cmd
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddVdencCmd2CmdTest();

        //!
        //! \brief     Test  CalculatePictureStateCommandSize
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS CalculatePictureStateCommandSizeTest();

        //!
        //! \brief     Test  PatchSliceLevelCommands
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS PatchSliceLevelCommandsTest();

        //!
        //! \brief     Test  PatchTileLevelCommands
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS PatchTileLevelCommandsTest();

        //!
        //! \brief     Test  AddOneTileCommands
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddOneTileCommandsTest();

        //!
        //! \brief     Test  AddSlicesCommandsInTile
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddSlicesCommandsInTileTest();

        //!
        //! \brief     Test  UpdateParameters
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS UpdateParametersTest();

        //!
        //! \brief     Test  AddPicStateWithNoTile
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddPicStateWithNoTileTest();

        //!
        //! \brief     Test  AddPicStateWithTile
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddPicStateWithTileTest();

        //!
        //! \brief     Test  AddHcpPipeBufAddrCmd
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddHcpPipeBufAddrCmdTest();

        //!
        //! \brief     Test  AddPictureHcpCommands
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddPictureHcpCommandsTest();

        //!
        //! \brief     Test  AddVdencWalkerStateCmd
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddVdencWalkerStateCmdTest();

        //!
        //! \brief     Test  SetHcpPipeBufAddrParams
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SetHcpPipeBufAddrParamsTest();

        //!
        //! \brief     Test  AddPictureVdencCommands
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddPictureVdencCommandsTest();

        //!
        //! \brief     Test  SetVdencPipeBufAddrParams
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SetVdencPipeBufAddrParamsTest();

        //!
        //! \brief     Test  PatchPictureLevelCommands
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS PatchPictureLevelCommandsTest();

        //!
        //! \brief     Test  InsertSeqStreamEnd
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS InsertSeqStreamEndTest();

        //!
        //! \brief     Test  EnsureAllCommandsExecuted
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS EnsureAllCommandsExecutedTest();

        //!
        //! \brief     Test  SetHcpPipeModeSelectParams
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SetHcpPipeModeSelectParamsTest();

        //!
        //! \brief     Test  AddHcpRefIdxCmd
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddHcpRefIdxCmdTest();

        //!
        //! \brief     Test  AddHcpPipeModeSelect
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddHcpPipeModeSelectTest();

        //!
        //! \brief     Test  AddHcpSurfaces
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AddHcpSurfacesTest();

        //!
        //! \brief     Test  SetVdencPipeModeSelectParams
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SetVdencPipeModeSelectParamsTest();

        //!
        //! \brief     Test  SetHcpSliceStateCommonParams
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SetHcpSliceStateCommonParamsTest();

        //!
        //! \brief     Test  SetHcpSliceStateParams
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS SetHcpSliceStateParamsTest();

        //!
        //! \brief     Test  Construct3rdLevelBatch
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS Construct3rdLevelBatchTest();

        //!
        //! \brief     Test  AllocateResources
        //!
        //! \return    MOS_STATUS
        //!            MOS_STATUS_SUCCESS if success, else fail reason
        //!
        MOS_STATUS AllocateResourcesTest();

    private:
        HevcVdencPipelineG12 *m_hevcVdencPipelineG12;

    };
}
#endif
