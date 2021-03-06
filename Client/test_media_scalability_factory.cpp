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
//! \file     test_media_scalability_factory.cpp
//! \brief    implementation file of TestMediaScalabilityFactory class
//! \a mock derived from test_media_scalability_factory and used for ult test
//!


namespace 
{
        MOS_STATUS TestMediaScalabilityFactory::CreateScalabilityTest()
        {
            uint8_t componentType = 0;

            ScalabilityPars *params;
            memset(&params, 0, sizeof(params));

            void *hwInterface = nullptr;

            MediaContext *mediaContext;
            memset(&mediaContext, 0, sizeof(mediaContext));

            MOS_GPUCTX_CREATOPTIONS *gpuCtxCreateOption;
            memset(&gpuCtxCreateOption, 0, sizeof(gpuCtxCreateOption));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestMediaScalabilityFactory::CreateEncodeScalabilityTest()
        {
            ScalabilityPars *params;
            memset(&params, 0, sizeof(params));

            void *hwInterface = nullptr;

            MediaContext *mediaContext;
            memset(&mediaContext, 0, sizeof(mediaContext));

            MOS_GPUCTX_CREATOPTIONS *gpuCtxCreateOption;
            memset(&gpuCtxCreateOption, 0, sizeof(gpuCtxCreateOption));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestMediaScalabilityFactory::CreateDecodeScalabilityTest()
        {
            ScalabilityPars *params;
            memset(&params, 0, sizeof(params));

            void *hwInterface = nullptr;

            MediaContext *mediaContext;
            memset(&mediaContext, 0, sizeof(mediaContext));

            MOS_GPUCTX_CREATOPTIONS *gpuCtxCreateOption;
            memset(&gpuCtxCreateOption, 0, sizeof(gpuCtxCreateOption));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestMediaScalabilityFactory::CreateVpScalabilityTest()
        {
            ScalabilityPars *params;
            memset(&params, 0, sizeof(params));

            void *hwInterface = nullptr;

            MediaContext *mediaContext;
            memset(&mediaContext, 0, sizeof(mediaContext));

            MOS_GPUCTX_CREATOPTIONS *gpuCtxCreateOption;
            memset(&gpuCtxCreateOption, 0, sizeof(gpuCtxCreateOption));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestMediaScalabilityFactory::CreateScalabilityMdfTest()
        {
            ScalabilityPars *params;
            memset(&params, 0, sizeof(params));


            return MOS_STATUS_SUCCESS;
        }

        MOS_STATUS TestMediaScalabilityFactory::CreateScalabilityCmdBufTest()
        {
            uint8_t componentType = 0;

            ScalabilityPars *params;
            memset(&params, 0, sizeof(params));

            void *hwInterface = nullptr;

            MediaContext *mediaContext;
            memset(&mediaContext, 0, sizeof(mediaContext));

            MOS_GPUCTX_CREATOPTIONS *gpuCtxCreateOption;
            memset(&gpuCtxCreateOption, 0, sizeof(gpuCtxCreateOption));


            return MOS_STATUS_SUCCESS;
        }

}
