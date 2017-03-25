include $(PETSC_DIR)/lib/petsc/conf/variables

bin_PROGRAMS = diffusiveTermTest2d \
               diffusiveTermTest3d

diffusiveTermTest2d_SOURCES = DiffusiveTerm.cpp \
                              test.cpp

diffusiveTermTest2d_DEPENDENCIES = input_data

diffusiveTermTest2d_CPPFLAGS = -I$(top_srcdir)/src/utilities \
                               -I$(top_srcdir)/src/solvers \
                               -D DIMENSIONS=2

diffusiveTermTest2d_LDADD = $(top_builddir)/src/solvers/libsolvers.a \
                            $(top_builddir)/src/utilities/libutilities.a \
                            $(top_builddir)/external/yaml-cpp-0.5.1/libyamlcpp.a

if WITH_AMGXWRAPPER
diffusiveTermTest2d_LDADD += $(top_builddir)/external/AmgXWrapper-1.0-beta2/libamgxwrapper.a
endif

diffusiveTermTest3d_SOURCES = DiffusiveTerm.cpp \
                              test.cpp

diffusiveTermTest3d_DEPENDENCIES = input_data

diffusiveTermTest3d_CPPFLAGS = -I$(top_srcdir)/src/utilities \
                               -I$(top_srcdir)/src/solvers \
                               -D DIMENSIONS=3

diffusiveTermTest3d_LDADD = $(top_builddir)/src/solvers/libsolvers.a \
                            $(top_builddir)/src/utilities/libutilities.a \
                            $(top_builddir)/external/yaml-cpp-0.5.1/libyamlcpp.a

if WITH_AMGXWRAPPER
diffusiveTermTest3d_LDADD += $(top_builddir)/external/AmgXWrapper-1.0-beta2/libamgxwrapper.a
endif

input_data:
	@echo "Copying cases folder..."
	@if test "$(top_srcdir)" != "$(top_builddir)" ; then \
	  cp -r $(top_srcdir)/tests/unittests/diffusiveTerms/cases $(PWD) ; \
	  cp $(top_srcdir)/tests/unittests/diffusiveTerms/plotGridConvergence.py $(PWD) ; \
	fi ;

N = 2
tests:
	@echo "Running 2D diffusive-term tests..."
	@mkdir -p  data
	@$(RM) data/relativeErrors2d.dat
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest2d -directory ./cases/2d/6
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest2d -directory ./cases/2d/12
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest2d -directory ./cases/2d/24
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest2d -directory ./cases/2d/48
	@echo "Running 3D diffusive-term tests..."
	@$(RM) -f data/relativeErrors3d.dat
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest3d -directory ./cases/3d/6
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest3d -directory ./cases/3d/12
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest3d -directory ./cases/3d/24
	@$(MPIEXEC) -n $(N) ./diffusiveTermTest3d -directory ./cases/3d/48
	@echo "Plotting grid convergence for diffusive-term tests..."
	@python plotGridConvergence.py

.PHONY: input_data tests