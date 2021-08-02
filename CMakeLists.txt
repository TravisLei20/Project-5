cmake_minimum_required(VERSION 3.16)
project(Project_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_5
        Automaton.h
        BadBlockCommentAutomaton.h
        BadStringAutomaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommentAutomaton.h
        Database.h
        DatalogProgram.h
        Header.h
        IDAutomaton.h
        Interpreter.h
        Lexer.cpp
        Lexer.h
        main.cpp
        MatcherAutomaton.cpp
        MatcherAutomaton.h
        Parameter.h
        Parser.cpp
        Parser.h
        Predicate.h
        Relation.h
        Rules.h
        StringAutomaton.h
        Token.cpp
        Token.h
        Tuple.h Graph.h)
