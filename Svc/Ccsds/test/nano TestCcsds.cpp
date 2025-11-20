#include <Svc/Ccsds/Ccsds.hpp>
#include <gtest/gtest.h>

TEST(Ccsds, EncodeDecodeBasic) {
    Svc::CcsdsPacket pkt;
    pkt.seq = 1;
    pkt.data[0] = 0xAB;

    U8 buffer[256];
    const U32 size = Svc::encodeCcsds(pkt, buffer, sizeof(buffer));

    ASSERT_GT(size, 0);

    Svc::CcsdsPacket decoded;
    ASSERT_TRUE(Svc::decodeCcsds(buffer, size, decoded));
    ASSERT_EQ(decoded.seq, 1);
    ASSERT_EQ(decoded.data[0], 0xAB);
}
