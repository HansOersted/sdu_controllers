#pragma once
#ifndef SDU_CONTROLLERS_BLEEDING_BLANKET_ROBOT_MODEL_HPP
#define SDU_CONTROLLERS_BLEEDING_BLANKET_ROBOT_MODEL_HPP

#include <vector>
#include <Eigen/Dense>
#include <sdu_controllers/models/robot_model.hpp>

namespace sdu_controllers::models
{

/**
 * This class provides a robot model for the EUROfusion breeding blanket handling robot.
 */

class BreedingBlanketHandlingRobotModel : public RobotModel
{
public:
  static constexpr uint16_t ROBOT_DOF = 7;

  BreedingBlanketHandlingRobotModel();

  /**
   * @brief Get inertia matrix \f$ \mathbf{B}(q) \f$
   * @param q the robot joint configuration.
   * @returns the inertia matrix.
   */
  Eigen::MatrixXd get_inertia_matrix(const Eigen::VectorXd &q) override;

  /**
   * @brief Get coriolis matrix \f$ \mathbf{C}(q, \dot{q}) \f$
   * @param q the robot joint configuration.
   * @param qd the robot joint configuration.
   * @returns the coriolis matrix.
   */
  Eigen::MatrixXd get_coriolis(const Eigen::VectorXd &q, const Eigen::VectorXd &qd) override;

  /**
   * @brief Get gravity term \f$ \tau_{g} \f$
   */
  Eigen::MatrixXd get_gravity(const Eigen::VectorXd &q) override;

  /**
   * @brief Get the jacobian \f$ \mathbf{J(q)} \f$
   * @returns the jacobian
   */
  Eigen::MatrixXd get_jacobian(const Eigen::VectorXd &q) override;

  /**
   * @brief Get jacobian dot \f$ \mathbf{\dot{J(q, dq)}} \f$
   * @returns the jacobian dot
   */
  Eigen::MatrixXd get_jacobian_dot(const Eigen::VectorXd &q, const Eigen::VectorXd &dq) override;

  /**
* @brief Get joint position bounds.
* @returns the joint position bounds
*/
  std::pair<Eigen::VectorXd, Eigen::VectorXd> get_joint_pos_bounds() override;

  /**
   * @brief Get joint velocity bounds.
   * @returns the joint velocity bounds
   */
  std::pair<Eigen::VectorXd, Eigen::VectorXd> get_joint_vel_bounds() override;

  /**
   * @brief Get joint acceleration bounds.
   * @returns the joint acceleration bounds
   */
  std::pair<Eigen::VectorXd, Eigen::VectorXd> get_joint_acc_bounds() override;

  /**
   * @brief Get joint torque bounds.
   * @returns the joint torque bounds
   */
  std::pair<Eigen::VectorXd, Eigen::VectorXd> get_joint_torque_bounds() override;

  uint16_t get_dof() const;

  std::vector<double> get_a() override;

  std::vector<double> get_d() override;

  std::vector<double> get_alpha() override;

private:
  uint16_t dof_{ROBOT_DOF};
  std::vector<double> a_;
  std::vector<double> d_;
  std::vector<double> alpha_;
  std::pair<Eigen::VectorXd, Eigen::VectorXd> joint_pos_bounds_;
  std::pair<Eigen::VectorXd, Eigen::VectorXd> joint_vel_bounds_;
  std::pair<Eigen::VectorXd, Eigen::VectorXd> joint_acc_bounds_;
  std::pair<Eigen::VectorXd, Eigen::VectorXd> joint_torque_bounds_;

};

} // namespace sdu_controllers::models

#endif  // SDU_CONTROLLERS_BLEEDING_BLANKET_ROBOT_MODEL_HPP
