check_PROGRAMS = test

test_SOURCES = test.cpp

test_DEPENDENCIES = input_data

test_CPPFLAGS = -I$(top_srcdir)/src/utilities \
                -I$(top_srcdir)/external/gtest-1.7.0/include \
                -I$(top_srcdir)/external/yaml-cpp-0.5.1/include

test_LDADD = $(top_builddir)/src/utilities/libutilities.a \
             $(top_builddir)/external/gtest-1.7.0/libgtest.a \
             $(top_builddir)/external/yaml-cpp-0.5.1/libyamlcpp.a

input_data:
	if test "$(top_srcdir)" != "$(top_builddir)" ; then \
	  cp -r $(top_srcdir)/tests/unittests/cartesianMesh/cases $(PWD) ; \
	fi ;

.PHONY: input_data
