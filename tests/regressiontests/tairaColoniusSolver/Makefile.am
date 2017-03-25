check_PROGRAMS = test

test_SOURCES = test.cpp

test_DEPENDENCIES = input_data

test_CPPFLAGS = -I$(top_srcdir)/src/utilities \
                -I$(top_srcdir)/src/solvers \
                -I$(top_srcdir)/external/gtest-1.7.0/include \
                -I$(top_srcdir)/external/yaml-cpp-0.5.1/include

if WITH_AMGXWRAPPER
test_CPPFLAGS += -I$(top_srcdir)/external/AmgXWrapper-1.0-beta2/src
endif

test_LDADD = $(top_builddir)/src/solvers/libsolvers.a \
             $(top_builddir)/src/utilities/libutilities.a \
             $(top_builddir)/external/gtest-1.7.0/libgtest.a \
             $(top_builddir)/external/yaml-cpp-0.5.1/libyamlcpp.a

if WITH_AMGXWRAPPER
test_LDADD += $(top_builddir)/external/AmgXWrapper-1.0-beta2/libamgxwrapper.a
endif

input_data:
	if test "$(top_srcdir)" != "$(top_builddir)" ; then \
	  cp -r $(top_srcdir)/tests/regressiontests/tairaColoniusSolver/case $(PWD) ; \
	fi ;

.PHONY: input_data
