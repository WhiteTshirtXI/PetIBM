/***************************************************************************//**
 * \file createKSPs.inl
 * \author Anush Krishnan (anush.bu.edu)
 * \brief Implementation of the method `createKSPs` of the class `NavierStokesSolver`.
 */


/**
 * \brief Instantiates the different solvers of the problem.
 *
 * Two solvers:
 *  - a solver for the intermediate velocity fluxes,
 *  - a Poisson solver for the pressure.
 *
 * `kps1` is the solver. Here, we list the default characteristicss:
 * - iterative method: Conjugate-Gradient
 * - relative tolerance: \f$ 10^{-5} \f$
 * - initial guess computed from output vector supplied
 *
 * It is possible to give command-line arguments to define the solver,
 * using the prefix `sys1_`.
 *
 * `kps2` is the solver. Here, we list the default characteristicss:
 * - iterative method: Conjugate-Gradient
 * - relative tolerance: \f$ 10^{-5} \f$
 * - initial guess computed from output vector supplied
 *
 * It is possible to give command-line arguments to define the solver,
 * using the prefix `sys2_`.
 */
template <PetscInt dim>
PetscErrorCode NavierStokesSolver<dim>::createKSPs()
{
  PetscErrorCode ierr;

  // file with KSP options
  std::string petscOptionsFile= parameters->directory + "/solversPetscOptions.info";
  ierr = PetscOptionsInsertFile(PETSC_COMM_WORLD, petscOptionsFile.c_str(), PETSC_FALSE); CHKERRQ(ierr);

  // create KSP for intermaediate fluxes system
  ierr = KSPCreate(PETSC_COMM_WORLD, &ksp1); CHKERRQ(ierr);
  ierr = KSPSetOptionsPrefix(ksp1, "velocity_"); CHKERRQ(ierr);
  ierr = KSPSetOperators(ksp1, A, A); CHKERRQ(ierr);
  ierr = KSPSetInitialGuessNonzero(ksp1, PETSC_TRUE); CHKERRQ(ierr);
  ierr = KSPSetType(ksp1, KSPCG); CHKERRQ(ierr);
  ierr = KSPSetReusePreconditioner(ksp1, PETSC_TRUE); CHKERRQ(ierr);
  ierr = KSPSetFromOptions(ksp1); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD, "\n----------------------------------------\n"); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD, "KSP info: Velocity system"); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD, "\n----------------------------------------\n"); CHKERRQ(ierr);
  ierr = KSPView(ksp1, PETSC_VIEWER_STDOUT_WORLD); CHKERRQ(ierr);

  // create KSP for Poisson system
  ierr = KSPCreate(PETSC_COMM_WORLD, &ksp2); CHKERRQ(ierr);
  ierr = KSPSetOptionsPrefix(ksp2, "poisson_"); CHKERRQ(ierr);
  ierr = KSPSetOperators(ksp2, QTBNQ, QTBNQ); CHKERRQ(ierr);
  ierr = KSPSetInitialGuessNonzero(ksp2, PETSC_TRUE); CHKERRQ(ierr);
  ierr = KSPSetType(ksp2, KSPCG); CHKERRQ(ierr);
  ierr = KSPSetReusePreconditioner(ksp2, PETSC_TRUE); CHKERRQ(ierr);
  ierr = KSPSetFromOptions(ksp2); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD, "\n----------------------------------------\n"); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD, "KSP info: Poisson system"); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD, "\n----------------------------------------\n"); CHKERRQ(ierr);
  ierr = KSPView(ksp2, PETSC_VIEWER_STDOUT_WORLD); CHKERRQ(ierr);

  return 0;
} // createKSPs