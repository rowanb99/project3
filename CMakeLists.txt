cmake_minimum_required(VERSION 3.23)
project(project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project3
        AddAutomaton.cpp
        AddAutomaton.h
        Automaton.h
        BlockComment_Automaton.cpp
        BlockComment_Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommAutomaton.cpp
        CommAutomaton.h
        DatalogProgram.cpp
        DatalogProgram.h
        EOF_Automaton.cpp
        EOF_Automaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        ID_Automaton.cpp
        ID_Automaton.h
        Left_ParenAutomaton.cpp
        Left_ParenAutomaton.h
        Lexer.cpp
        Lexer.h
        LineCommentAutomaton.cpp
        LineCommentAutomaton.h
        main.cpp
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        Parser.cpp
        Parser.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        Q_markAutomaton.cpp
        Q_markAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        Right_ParenAutomaton.cpp
        Right_ParenAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        Token.cpp
        Token.h)
