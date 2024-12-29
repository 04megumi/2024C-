#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"
namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{
    return std::tie(lhs.x,lhs.y,lhs.heading)==std::tie(rhs.x,rhs.y,rhs.heading);
}

TEST(ExecutorTest,should_return_init_pose_when_without_command)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

    //when

    //then
    const Pose target({0,0,'E'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_default_pose_when_without_init_and_command)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor());

    //when

    //then
    const Pose target({0,0,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

    //when
    executor->Execute("M");

    //then
    const Pose target({1,0,'E'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

    //when
    executor->Execute("M");

    //then
    const Pose target({-1,0,'W'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("M");

    //then
    const Pose target({0,1,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

    //when
    executor->Execute("M");

    //then
    const Pose target({0,-1,'S'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

    //when
    executor->Execute("L");

    //then
    const Pose target({0,0,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("L");

    //then
    const Pose target({0,0,'W'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

    //when
    executor->Execute("L");

    //then
    const Pose target({0,0,'S'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

    //when
    executor->Execute("L");

    //then
    const Pose target({0,0,'E'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

    //when
    executor->Execute("R");

    //then
    const Pose target({0,0,'S'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

    //when
    executor->Execute("R");

    //then
    const Pose target({0,0,'W'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_N_given_command_is_R_and_facing_is_W)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

    //when
    executor->Execute("R");

    //then
    const Pose target({0,0,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("R");

    //then
    const Pose target({0,0,'E'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

    //when
    executor->Execute("FM");

    //then
    const Pose target({2,0,'E'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

    //when
    executor->Execute("FL");

    //then
    const Pose target({1,0,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_S_and_x_plus_1_given_status_is_fast_command_is_R_and_facing_is_E)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

    //when
    executor->Execute("FR");

    //then
    const Pose target({1,0,'S'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor());

    //when
    executor->Execute("FFM");

    //then
    const Pose target({0,1,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_minus_1_given_command_is_BM_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("BM");

    //then
    const Pose target({0,-1,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_E_given_command_is_BL_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("BL");

    //then
    const Pose target({0,0,'E'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_facing_E_given_command_is_BR_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("BR");

    //then
    const Pose target({0,0,'W'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_minus_2_given_command_is_BFM_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("BFM");

    //then
    const Pose target({0,-2,'N'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_minus_1_facing_E_given_command_is_BFL_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("BFL");

    //then
    const Pose target({0,-1,'E'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_minus_1_facing_W_given_command_is_BFR_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("BFR");

    //then
    const Pose target({0,-1,'W'});
    ASSERT_EQ(target,executor->Query());
}

TEST(ExecutorTest,should_return_y_plus_1_facing_N_given_command_is_BBM_and_facing_is_N)
{
    //given
    std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

    //when
    executor->Execute("BBM");

    //then
    const Pose target({0,1,'N'});
    ASSERT_EQ(target,executor->Query());
}
 

}