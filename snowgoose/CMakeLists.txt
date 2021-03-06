cmake_minimum_required(VERSION 3.9)
project(snowgoose)

set(CMAKE_CXX_STANDARD 11)

add_executable(snowgoose
    box/box.hpp
    box/boxutils.hpp
    common/fileutils.hpp
    common/interval.hpp
    common/projecttosimplex.hpp
    common/sgerrcheck.hpp
    common/smartptr.hpp
    common/testprojecttosimplex.cpp
    common/utilmacro.hpp
    common/vec.hpp
    derivatives/grad.hpp
    derivatives/helpfunc.hpp
    derivatives/intervalder.hpp
    derivatives/testderivative.cpp
    derivatives/valder.hpp
    expression/algder.hpp
    expression/algorithm.hpp
    expression/expr.hpp
    expression/node.hpp
    expression/testexpr.cpp
    expression/utils.h
    interval/enums.h
    interval/interval_air.hpp
    interval/testinterval.cpp
    libjson/_internal/Dependencies/libbase64++/libbase64++.h
    libjson/_internal/Dependencies/mempool++/mempool.h
    libjson/_internal/Source/JSONDefs/GNU_C.h
    libjson/_internal/Source/JSONDefs/Strings_Defs.h
    libjson/_internal/Source/JSONDefs/Unknown_C.h
    libjson/_internal/Source/JSONDefs/Visual_C.h
    libjson/_internal/Source/internalJSONNode.cpp
    libjson/_internal/Source/internalJSONNode.h
    libjson/_internal/Source/JSON_Base64.h
    libjson/_internal/Source/JSONAllocator.cpp
    libjson/_internal/Source/JSONAllocator.h
    libjson/_internal/Source/JSONChildren.cpp
    libjson/_internal/Source/JSONChildren.h
    libjson/_internal/Source/JSONDebug.cpp
    libjson/_internal/Source/JSONDebug.h
    libjson/_internal/Source/JSONDefs.h
    libjson/_internal/Source/JSONGlobals.h
    libjson/_internal/Source/JSONIterators.cpp
    libjson/_internal/Source/JSONMemory.cpp
    libjson/_internal/Source/JSONMemory.h
    libjson/_internal/Source/JSONMemoryPool.h
    libjson/_internal/Source/JSONNode.cpp
    libjson/_internal/Source/JSONNode.h
    libjson/_internal/Source/JSONNode_Mutex.cpp
    libjson/_internal/Source/JSONPreparse.cpp
    libjson/_internal/Source/JSONPreparse.h
    libjson/_internal/Source/JSONSharedString.h
    libjson/_internal/Source/JSONSingleton.h
    libjson/_internal/Source/JSONStats.h
    libjson/_internal/Source/JSONStream.cpp
    libjson/_internal/Source/JSONStream.h
    libjson/_internal/Source/JSONValidator.cpp
    libjson/_internal/Source/JSONValidator.h
    libjson/_internal/Source/JSONWorker.cpp
    libjson/_internal/Source/JSONWorker.h
    libjson/_internal/Source/JSONWriter.cpp
    libjson/_internal/Source/libjson.cpp
    libjson/_internal/Source/NumberToString.h
    libjson/_internal/TestSuite/All/main.cpp
    libjson/_internal/TestSuite/Benchmark/main.cpp
    libjson/_internal/TestSuite/main.cpp
    libjson/_internal/TestSuite/RunTestSuite2.cpp
    libjson/_internal/TestSuite/RunTestSuite2.h
    libjson/_internal/TestSuite/StringTest.h
    libjson/_internal/TestSuite/TestAssign.cpp
    libjson/_internal/TestSuite/TestBinary.cpp
    libjson/_internal/TestSuite/TestChildren.cpp
    libjson/_internal/TestSuite/TestComments.cpp
    libjson/_internal/TestSuite/TestConverters.cpp
    libjson/_internal/TestSuite/TestCtors.cpp
    libjson/_internal/TestSuite/TestEquality.cpp
    libjson/_internal/TestSuite/TestFunctions.cpp
    libjson/_internal/TestSuite/TestInequality.cpp
    libjson/_internal/TestSuite/TestInspectors.cpp
    libjson/_internal/TestSuite/TestIterators.cpp
    libjson/_internal/TestSuite/TestMutex.cpp
    libjson/_internal/TestSuite/TestNamespace.cpp
    libjson/_internal/TestSuite/TestRefCounting.cpp
    libjson/_internal/TestSuite/TestSharedString.cpp
    libjson/_internal/TestSuite/TestStreams.cpp
    libjson/_internal/TestSuite/TestString.cpp
    libjson/_internal/TestSuite/TestSuite.cpp
    libjson/_internal/TestSuite/TestSuite.h
    libjson/_internal/TestSuite/TestValidator.cpp
    libjson/_internal/TestSuite/TestWriter.cpp
    libjson/_internal/TestSuite/UnitTest.cpp
    libjson/_internal/TestSuite/UnitTest.h
    libjson/_internal/TestSuite/UStringTest.h
    libjson/_internal/TestSuite2/JSON_Base64/json_decode64.cpp
    libjson/_internal/TestSuite2/JSON_Base64/json_decode64.h
    libjson/_internal/TestSuite2/JSON_Base64/json_encode64.cpp
    libjson/_internal/TestSuite2/JSON_Base64/json_encode64.h
    libjson/_internal/TestSuite2/JSONDebug/JSON_ASSERT.cpp
    libjson/_internal/TestSuite2/JSONDebug/JSON_ASSERT.h
    libjson/_internal/TestSuite2/JSONDebug/JSON_ASSERT_SAFE.cpp
    libjson/_internal/TestSuite2/JSONDebug/JSON_ASSERT_SAFE.h
    libjson/_internal/TestSuite2/JSONDebug/JSON_FAIL.cpp
    libjson/_internal/TestSuite2/JSONDebug/JSON_FAIL.h
    libjson/_internal/TestSuite2/JSONDebug/JSON_FAIL_SAFE.cpp
    libjson/_internal/TestSuite2/JSONDebug/JSON_FAIL_SAFE.h
    libjson/_internal/TestSuite2/JSONGlobals/jsonSingleton.cpp
    libjson/_internal/TestSuite2/JSONGlobals/jsonSingleton.h
    libjson/_internal/TestSuite2/JSONValidator/Resources/validyMacros.h
    libjson/_internal/TestSuite2/JSONValidator/isValidArray.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidArray.h
    libjson/_internal/TestSuite2/JSONValidator/isValidMember.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidMember.h
    libjson/_internal/TestSuite2/JSONValidator/isValidNamedObject.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidNamedObject.h
    libjson/_internal/TestSuite2/JSONValidator/isValidNumber.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidNumber.h
    libjson/_internal/TestSuite2/JSONValidator/isValidObject.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidObject.h
    libjson/_internal/TestSuite2/JSONValidator/isValidPartialRoot.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidPartialRoot.h
    libjson/_internal/TestSuite2/JSONValidator/isValidRoot.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidRoot.h
    libjson/_internal/TestSuite2/JSONValidator/isValidString.cpp
    libjson/_internal/TestSuite2/JSONValidator/isValidString.h
    libjson/_internal/TestSuite2/JSONValidator/securityTest.cpp
    libjson/_internal/TestSuite2/JSONValidator/securityTest.h
    libjson/_internal/TestSuite2/NumberToString/_areFloatsEqual.cpp
    libjson/_internal/TestSuite2/NumberToString/_areFloatsEqual.h
    libjson/_internal/TestSuite2/NumberToString/_atof.cpp
    libjson/_internal/TestSuite2/NumberToString/_atof.h
    libjson/_internal/TestSuite2/NumberToString/_ftoa.cpp
    libjson/_internal/TestSuite2/NumberToString/_ftoa.h
    libjson/_internal/TestSuite2/NumberToString/_itoa.cpp
    libjson/_internal/TestSuite2/NumberToString/_itoa.h
    libjson/_internal/TestSuite2/NumberToString/_uitoa.cpp
    libjson/_internal/TestSuite2/NumberToString/_uitoa.h
    libjson/_internal/TestSuite2/NumberToString/getLenSize.cpp
    libjson/_internal/TestSuite2/NumberToString/getLenSize.h
    libjson/_internal/TestSuite2/NumberToString/isNumeric.cpp
    libjson/_internal/TestSuite2/NumberToString/isNumeric.h
    libjson/_internal/TestSuite2/BaseTest.h
    libjson/JSONOptions.h
    libjson/libjson.h
    pointgen/pointgenerator.hpp
    pointgen/randpointgen.hpp
    pointgen/testrandpointgen.cpp)
