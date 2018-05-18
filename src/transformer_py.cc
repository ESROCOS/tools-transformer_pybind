#include <tools/transformer/Transformer.h>
#include <boost/python.hpp>

typedef esrocos::transformer::AcyclicTransformer<20,20> atf;

BOOST_PYTHON_MODULE(transformer_py)
{
  using namespace boost::python;

  const char * (atf::Frame::*id_get)() const = &atf::Frame::id;
  bool (atf::Frame::*id_set)(const char *) = &atf::Frame::id;

  class_<atf::Frame>("Frame", init<const char *>())
    .def("id",id_get)
    .def("id",id_set)
    ;
}
