SendAttrWithFrameTrackingTest()
{
    frameTrackingRequested = 1;
    m_frameTrackingEnabled = 1;
    EncodeScalabilitySinglePipe::SendAttrWithFrameTracking(cmdBuffer, frameTrackingRequested);
}
