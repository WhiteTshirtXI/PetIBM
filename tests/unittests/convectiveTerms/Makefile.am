include $(PETSC_DIR)/lib/petsc/conf/variables

bin_PROGRAMS = convectiveTermTest2d \
               convectiveTermTest3d

convectiveTermTest2d_SOURCES = ConvectiveTerm.cpp \
                               test.cpp

convectiveTermTest2d_DEPENDENCIES = input_data

convectiveTermTest2d_CPPFLAGS = -I$(top_srcdir)/src/utilities \
                                -I$(top_srcdir)/src/solvers \
                                -D DIMENSIONS=2

convectiveTermTest2d_LDADD = $(top_builddir)/src/solvers/libsolvers.a \
                             $(top_builddir)/src/utilities/libutilities.a \
                             $(top_builddir)/external/yaml-cpp-0.5.1/libyamlcpp.a

if WITH_AMGXWRAPPER
convectiveTermTest2d_LDADD += $(top_builddir)/external/AmgXWrapper-1.0-beta2/libamgxwrapper.a
endif

convectiveTermTest3d_SOURCES = ConvectiveTerm.cpp \
                               test.cpp

convectiveTermTest3d_DEPENDENCIES = input_data

convectiveTermTest3d_CPPFLAGS = -I$(top_srcdir)/src/utilities \
                                -I$(top_srcdir)/src/solvers \
                                -D DIMENSIONS=3

convectiveTermTest3d_LDADD = $(top_builddir)/src/solvers/libsolvers.a \
                             $(top_builddir)/src/utilities/libutilities.a \
                             $(top_builddir)/external/yaml-cpp-0.5.1/libyamlcpp.a

if WITH_AMGXWRAPPER
convectiveTermTest3d_LDADD += $(top_builddir)/external/AmgXWrapper-1.0-beta2/libamgxwrapper.a
endif

input_data:
	@echo "Copying cases folder..."
	@if test "$(top_srcdir)" != "$(top_builddir)" ; then \
	  cp -r $(top_srcdir)/tests/unittests/convectiveTerms/cases $(PWD) ; \
	  cp $(top_srcdir)/tests/unittests/convectiveTerms/plotGridConvergence.py $(PWD) ; \
	fi ;

N=2
tests:
	@echo "Running 2D convective-term tests..."
	@mkdir -p  data
	@$(RM) data/relativeErrors2d.dat
	@$(MPIEXEC) -n $(N) ./convectiveTermTest2d -directory ./cases/2d/6
	@$(MPIEXEC) -n $(N) ./convectiveTermTest2d -directory ./cases/2d/12
	@$(MPIEXEC) -n $(N) ./convectiveTermTest2d -directory ./cases/2d/24
	@$(MPIEXEC) -n $(N) ./convectiveTermTest2d -directory ./cases/2d/48
	@echo "Running 3D convective-term tests..."
	@$(RM) -f data/relativeErrors3d.dat
	@$(MPIEXEC) -n $(N) ./convectiveTermTest3d -directory ./cases/3d/6
	@$(MPIEXEC) -n $(N) ./convectiveTermTest3d -directory ./cases/3d/12
	@$(MPIEXEC) -n $(N) ./convectiveTermTest3d -directory ./cases/3d/24
	@$(MPIEXEC) -n $(N) ./convectiveTermTest3d -directory ./cases/3d/48
	@echo "Plotting grid convergence for convective-term tests..."
	@python plotGridConvergence.py

.PHONY: input_data tests
