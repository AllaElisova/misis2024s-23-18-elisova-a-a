add_executable (test_complex test_complex.cpp)
target_link_libraries (test_complex complex)

add_executable (test_rational test_rational.cpp)
target_link_libraries (test_rational rational)

add_executable (test_dynarr test_dynarr.cpp)
target_link_libraries (test_dynarr dynarr)

add_executable (test_stackarr test_stackarr.cpp)
target_link_libraries (test_stackarr stackarr)
target_link_libraries (test_stackarr complex)

add_executable (test_stacklst test_stacklst.cpp)
target_link_libraries (test_stacklst stacklst)
target_link_libraries (test_stacklst complex)

add_executable (test_queuelst test_queuelst.cpp)
target_link_libraries (test_queuelst queuelst)

add_executable (test_queuearr test_queuearr.cpp)
target_link_libraries (test_queuearr queuearr)

add_executable (test_queuelstpr test_queuelstpr.cpp)
target_link_libraries (test_queuelstpr queuelstpr)

add_executable (test_bitset test_bitset.cpp)
target_link_libraries (test_bitset bitset)

add_executable (test_stacklstt test_stacklstt.cpp)
target_link_libraries (test_stacklstt stacklstt)
target_link_libraries (test_stacklstt complex)
target_link_libraries (test_stacklstt rational)

add_executable (test_queuearrt test_queuearrt.cpp)
target_link_libraries (test_queuearrt queuearrt)
target_link_libraries (test_queuearrt complex)
target_link_libraries (test_queuearrt rational)

add_executable (test_queuelstt test_queuelstt.cpp)
target_link_libraries (test_queuelstt queuelstt)
target_link_libraries (test_queuelstt complex)
target_link_libraries (test_queuelstt rational)

add_executable (test_stackarrt test_stackarrt.cpp)
target_link_libraries (test_stackarrt stackarrt)
target_link_libraries (test_stackarrt complex)
target_link_libraries (test_stackarrt rational)

add_executable (test_queuelstprt test_queuelstprt.cpp)
target_link_libraries (test_queuelstprt queuelstprt)
target_link_libraries (test_queuelstprt complex)
target_link_libraries (test_queuelstprt rational)