/**
 * @file AquariumTest.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "gtest/gtest.h"
#include <pch.h>
#include <FishBeta.h>
#include <Aquarium.h>

using namespace std;

TEST(AquariumTest, Construct){
    Aquarium aquarium;
}

TEST(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    fish1->SetLocation(100, 200);
    aquarium.Add(fish1);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
                                                     L"Testing fish at 100, 200";
}

TEST(AquariumTest, TopFishTest){
    Aquarium aquarium;

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    fish1->SetLocation(100, 200);
    aquarium.Add(fish1);

    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
    fish2->SetLocation(100, 200);
    aquarium.Add(fish2);

    ASSERT_EQ(aquarium.HitTest(100,200), fish2);
    ASSERT_FALSE(aquarium.HitTest(100, 200) == fish1) << L"Top Fish Found.";
    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish2) <<
                                                     L"Top Fish Found.";
}

TEST(AquariumTest, EmptyImageTest){
    Aquarium aquarium;

    // Testing in empty aquarium
    ASSERT_EQ(aquarium.HitTest(100,200), nullptr) <<
                                                  L"Testing empty aquarium.";

    // Adding the fish
    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    fish1->SetLocation(100, 200);
    aquarium.Add(fish1);

    // Testing in filled Aquarium
    ASSERT_EQ(aquarium.HitTest(10,20), nullptr);
    ASSERT_EQ(aquarium.HitTest(500,600), nullptr);
    ASSERT_FALSE(aquarium.HitTest(100,200) == nullptr);

    // Adding second fish
    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
    fish2->SetLocation(500, 600);
    aquarium.Add(fish2);

    // Testing in more filled Aquarium
    ASSERT_EQ(aquarium.HitTest(10,20), nullptr);
    ASSERT_EQ(aquarium.HitTest(300,400), nullptr);
    ASSERT_FALSE(aquarium.HitTest(100,200) == nullptr);
}
