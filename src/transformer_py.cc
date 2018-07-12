#include <tools/transformer/Transformer.h>
#include <boost/python.hpp>


const int STRING_LEN = 50;

typedef esrocos::transformer::AcyclicTransformer<20,STRING_LEN> atf20;
typedef atf20::Frame frame;
typedef atf20::Transformation transform;

BOOST_PYTHON_MODULE(transformer_py)
{
  using namespace boost::python;

  const char * (frame::*id_get)() const = &frame::id;
  bool (frame::*id_set)(const char *) = &frame::id;

  class_<frame>("Frame", init<const char *>())
    .def("id",id_get)
    .def("id",id_set)
  ;

  bool (transform::*atob_set)(Eigen::Matrix4f) = &transform::atob;
  const Eigen::Matrix4f (transform::*atob_get)() const = &transform::atob; 

  bool (transform::*btoa_set)(Eigen::Matrix4f) = &transform::btoa;
  const Eigen::Matrix4f (transform::*btoa_get)() const = &transform::btoa; 

  class_<transform>("Transform",init<frame, frame, const char *>())
    .def("id",&transform::id)
    .def("a",&transform::a)
    .def("b",&transform::b)
    .def("atob",atob_get)
    .def("atob",atob_set)
    .def("btoa",btoa_get)
    .def("btoa",btoa_set)
  ;

  class_<atf20>("atf20", init<atf20::Frame&>())
    .def("ssize",&atf20::ssize)
    .def("maxFrames",&atf20::maxFrames)
    .def("getFrame",&atf20::getFrame)
    .def("addFrame",&atf20::addFrame)
    .def("updateFrame",&atf20::updateFrame)
    .def("removeFrame",&atf20::removeFrame)
    .def("getTransform",&atf20::getTransformAtoB)
    .def("updateTransform",&atf20::updateTransform)
  ;
}
