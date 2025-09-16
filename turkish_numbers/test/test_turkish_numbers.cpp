#include <gtest/gtest.h>
#include <string>
#include "src/main.cpp"

TEST(TurkishNumbersTest, BasicNumbers)
{
    EXPECT_EQ(numberToTurkish(0), "sıfır");
    EXPECT_EQ(numberToTurkish(1), "bir");
    EXPECT_EQ(numberToTurkish(5), "beş");
    EXPECT_EQ(numberToTurkish(9), "dokuz");
}

TEST(TurkishNumbersTest, Tens)
{
    EXPECT_EQ(numberToTurkish(10), "on");
    EXPECT_EQ(numberToTurkish(20), "yirmi");
    EXPECT_EQ(numberToTurkish(30), "otuz");
    EXPECT_EQ(numberToTurkish(40), "kırk");
    EXPECT_EQ(numberToTurkish(50), "elli");
    EXPECT_EQ(numberToTurkish(60), "altmış");
    EXPECT_EQ(numberToTurkish(70), "yetmiş");
    EXPECT_EQ(numberToTurkish(80), "seksen");
    EXPECT_EQ(numberToTurkish(90), "doksan");
}

TEST(TurkishNumbersTest, CompositeNumbers)
{
    EXPECT_EQ(numberToTurkish(13), "on üç");
    EXPECT_EQ(numberToTurkish(27), "yirmi yedi");
    EXPECT_EQ(numberToTurkish(38), "otuz sekiz");
    EXPECT_EQ(numberToTurkish(42), "kırk iki");
    EXPECT_EQ(numberToTurkish(55), "elli beş");
    EXPECT_EQ(numberToTurkish(66), "altmış altı");
    EXPECT_EQ(numberToTurkish(77), "yetmiş yedi");
    EXPECT_EQ(numberToTurkish(88), "seksen sekiz");
    EXPECT_EQ(numberToTurkish(99), "doksan dokuz");
}

TEST(TurkishNumbersTest, EdgeCases)
{
    EXPECT_EQ(numberToTurkish(11), "on bir");
    EXPECT_EQ(numberToTurkish(22), "yirmi iki");
    EXPECT_EQ(numberToTurkish(33), "otuz üç");
    EXPECT_EQ(numberToTurkish(44), "kırk dört");
}

TEST(TurkishNumbersTest, OutOfRange)
{
    EXPECT_THROW(numberToTurkish(-1), std::out_of_range);
    EXPECT_THROW(numberToTurkish(100), std::out_of_range);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}