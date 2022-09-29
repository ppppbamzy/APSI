#include <pybind11/pybind11.h>
#include "sender/apsi/sender_db.h"

namespace py = pybind11;

using namespace apsi;
using namespace apsi::sender;

PYBIND11_MODULE(pyapsi, m) {
    m.doc() = "pybind11 pyapsi plugin";  // Optional module docstring

    py::class_<SenderDB>(m, "SenderDB")
        .def(py::init<PSIParams, std::size_t, std::size_t, bool>(), py::arg("params"), py::arg("label_byte_count") = 0, py::arg("nonce_byte_count") = 16, py::arg("compressed") = true, "Creates a new SenderDB.")
        .def(py::init<PSIParams, oprf::OPRFKey, std::size_t, std::size_t, bool>(), py::arg("params"), py::arg("oprf_key"), py::arg("label_byte_count") = 0, py::arg("nonce_byte_count") = 16, py::arg("compressed") = true, "Creates a new SenderDB.")
//   TODO     .def(py::init<SenderDB &&>(), "Creates a new SenderDB by moving from an existing one.")
//       .def(py::init<SenderDB >(), py::arg("source"), "Creates a new SenderDB by moving from an existing one.")
//   TODO     .def(py::init<SenderDB &&>(), "Moves an existing SenderDB to the current one.")

        .def("clear", &SenderDB::clear, "Clears the database. Every item and label will be removed. The OPRF key is unchanged.")
        .def("is_labeled", &SenderDB::is_labeled, "Returns whether this is a labeled SenderDB.")
        .def("get_label_byte_count", &SenderDB::get_label_byte_count, "Returns the label byte count. A zero value indicates an unlabeled SenderDB.")
        .def("get_nonce_byte_count", &SenderDB::get_nonce_byte_count, "Returns the nonce byte count used for encrypting labels.")
        .def("is_compressed", &SenderDB::is_compressed, "Indicates whether SEAL plaintexts are compressed in memory.")
        .def("is_stripped", &SenderDB::is_stripped, "Indicates whether the SenderDB has been stripped of all information not needed for serving a query.")
//        .def("insert_or_assign", static_cast<void (Sender_db::*)(const std::vector<std::pair<Item, Label>> &)> (&Sender_db::insert_or_assign), "Inserts the given data into the database. This function can be used only on a labeled SenderDB instance. If an item already exists in the database, its label is overwritten with the new label.")
//        .def("insert_or_assign", static_cast<void (Sender_db::*)(const std::pair<Item, Label> &)> (&Sender_db::insert_or_assign), "Inserts the given (hashed) item-label pair into the database. This function can be used only on a labeled SenderDB instance. If the item already exists in the database, its label is overwritten with the new label.")
//        .def("insert_or_assign", static_cast<void (Sender_db::*)(const std::vector<Item> &)> (&Sender_db::insert_or_assign), "Inserts the given data into the database. This function can be used only on an unlabeled SenderDB instance.")
//        .def("insert_or_assign", static_cast<void (Sender_db::*)(const Item &)> (&Sender_db::insert_or_assign), "Inserts the given (hashed) item into the database. This function can be used only on an unlabeled SenderDB instance.")
        .def("set_data", static_cast<void (SenderDB::*)(const std::vector<std::pair<Item, Label>> &)> (&SenderDB::set_data), "Clears the database and inserts the given data. This function can be used only on a labeled SenderDB instance.")
        .def("set_data", static_cast<void (SenderDB::*)(const std::vector<Item> &)> (&SenderDB::set_data), "Clears the database and inserts the given data. This function can be used only on an unlabeled SenderDB instance.")
//        .def("", &Sender_db::, "")
        ;

//    m.def("")
}