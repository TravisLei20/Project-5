//
// Created by travi on 7/6/2021.
//

#include "Parser.h"

using namespace std;

void Parser::schemeList()
{
    if (tokens.at(index) -> getTokenType() != TokenType::FACTS)
    {
        scheme();
        schemeList();
    }
}

void Parser::factList()
{
    if (tokens.at(index) -> getTokenType() != TokenType::RULES)
    {
        fact();
        factList();
    }
}

void Parser::ruleList()
{
    if (tokens.at(index) -> getTokenType() != TokenType::QUERIES)
    {
        rule();
        ruleList();
    }
}

void Parser::queryList()
{
    if (tokens.at(index) -> getTokenType() != TokenType::EOF_TYPE)
    {
        query();
        queryList();
    }
}

void Parser::scheme()
{
    string nameOfThePredicate;

    if (tokens.at(index) -> getTokenType() == TokenType::ID)
    {
        nameOfThePredicate = tokens.at(index) -> getString();
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::LEFT_PAREN)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::ID)
    {
        Parameter parameter1(tokens.at(index) -> getString());
        vectorOfParameters.push_back(parameter1);
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() != TokenType::RIGHT_PAREN)
    {
        idList();
    }

    if (tokens.at(index) -> getTokenType() == TokenType::RIGHT_PAREN)
    {
        Predicate predicate1(nameOfThePredicate , vectorOfParameters);
        datalogProgram1.setScheme(predicate1);
        vectorOfParameters.clear();
        index++;
    }
    else
    {
        throw tokens.at(index);
    }
}

void Parser::fact()
{
    string nameOfThePredicate;

    if (tokens.at(index) -> getTokenType() == TokenType::ID)
    {
        nameOfThePredicate = tokens.at(index) -> getString();
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::LEFT_PAREN)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::STRING)
    {
        Parameter parameter1(tokens.at(index) -> getString());
        vectorOfParameters.push_back(parameter1);
        setDomain.insert(tokens.at(index) -> getString());
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() != TokenType::RIGHT_PAREN)
    {
        stringList();
    }

    if (tokens.at(index) -> getTokenType() == TokenType::RIGHT_PAREN)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::PERIOD)
    {
        Predicate predicate1(nameOfThePredicate , vectorOfParameters);
        datalogProgram1.setFacts(predicate1);
        vectorOfParameters.clear();
        index++;
    }
    else
    {
        throw tokens.at(index);
    }
}

void Parser::rule()
{
    headPredicate();
    rules.clearVector();

    if (tokens.at(index) -> getTokenType() == TokenType::COLON_DASH)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    rules.pushbackPredicate(predicate());

    if (tokens.at(index) -> getTokenType() != TokenType::PERIOD)
    {
        predicateList();
    }

    if (tokens.at(index) -> getTokenType() == TokenType::PERIOD)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }
    datalogProgram1.setRule(rules);
}

void Parser::query()
{
    string nameOfThePredicate;

    datalogProgram1.setQueries(predicate());
    vectorOfParameters.clear();

    if (tokens.at(index) -> getTokenType() == TokenType::Q_MARK)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }
}

void Parser::headPredicate()
{
    if (tokens.at(index) -> getTokenType() == TokenType::ID)
    {
        nameOfHeadPredicate.setID(tokens.at(index) -> getString());
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::LEFT_PAREN)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::ID)
    {
        Parameter parameter1(tokens.at(index) -> getString());
        vectorOfParameters.push_back(parameter1);
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() != TokenType::RIGHT_PAREN)
    {
        idList();
    }

    if (tokens.at(index) -> getTokenType() == TokenType::RIGHT_PAREN)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    nameOfHeadPredicate.setParameter(vectorOfParameters);
    vectorOfParameters.clear();
    rules.setHeadPredicate(nameOfHeadPredicate);

}

Predicate Parser::predicate()
{
    string nameOfThePredicate;

    if (tokens.at(index) -> getTokenType() == TokenType::ID)
    {
        nameOfThePredicate = tokens.at(index) -> getString();
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::LEFT_PAREN)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    parameter();

    if (tokens.at(index) -> getTokenType() != TokenType::RIGHT_PAREN)
    {
        parameterList();
    }

    Predicate predicate1(nameOfThePredicate , vectorOfParameters);
    vectorOfParameters.clear();

    if (tokens.at(index) -> getTokenType() == TokenType::RIGHT_PAREN)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }
    return predicate1;
}

void Parser::predicateList()
{
    if (tokens.at(index) -> getTokenType() == TokenType::COMMA)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    rules.pushbackPredicate(predicate());

    if (tokens.at(index) -> getTokenType() != TokenType::PERIOD)
    {
        predicateList();
    }

}

void Parser::parameterList()
{
    if (tokens.at(index) -> getTokenType() == TokenType::COMMA)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    parameter();

    if (tokens.at(index) -> getTokenType() != TokenType::RIGHT_PAREN)
    {
        parameterList();
    }

}

void Parser::stringList()
{
    if (tokens.at(index) -> getTokenType() == TokenType::COMMA)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::STRING)
    {
        Parameter parameter1(tokens.at(index) -> getString());
        vectorOfParameters.push_back(parameter1);
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() != TokenType::RIGHT_PAREN)
    {
        stringList();
    }
}

void Parser::idList()
{
    if (tokens.at(index) -> getTokenType() == TokenType::COMMA)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::ID)
    {
        Parameter parameter1(tokens.at(index) -> getString());
        vectorOfParameters.push_back(parameter1);
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() != TokenType::RIGHT_PAREN)
    {
        idList();
    }

}

void Parser::parameter()
{
    if ((tokens.at(index) -> getTokenType() == TokenType::ID) ||
    (tokens.at(index) -> getTokenType() == TokenType::STRING))
    {
        vectorOfParameters.push_back(tokens.at(index) -> getString());
        index++;
    }
    else
    {
        throw tokens.at(index);
    }
}



void Parser::datalogProgram()
{
    if (tokens.at(index) -> getTokenType() == TokenType::SCHEMES)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::COLON)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    scheme();
    schemeList();

    if (tokens.at(index) -> getTokenType() == TokenType::FACTS)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::COLON)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    factList();

    if (tokens.at(index) -> getTokenType() == TokenType::RULES)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::COLON)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    ruleList();

    if (tokens.at(index) -> getTokenType() == TokenType::QUERIES)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    if (tokens.at(index) -> getTokenType() == TokenType::COLON)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }

    query();
    queryList();

    if (tokens.at(index) -> getTokenType() == TokenType::EOF_TYPE)
    {
        index++;
    }
    else
    {
        throw tokens.at(index);
    }
}

void Parser::parse()
{
    try
    {
        datalogProgram();
        //cout << "Success!" << endl;
        //datalogProgram1.toString();
    }
    catch(Token* error)
    {
        cout << "Failure!" << endl;
        cout << "  " << error -> toString();
    }
}