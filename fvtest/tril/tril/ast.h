/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2017, 2017
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 ******************************************************************************/

#ifndef AST_H
#define AST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

typedef enum {Int64, Double, String} ASTValueType;

typedef struct ASTValue ASTValue;
typedef struct ASTNodeArg ASTNodeArg;
typedef struct ASTNode ASTNode;

ASTNode* createNode(const char* name, ASTNodeArg* args, ASTNode* children,  ASTNode* next);

ASTNodeArg* createNodeArg(const char* name, ASTValue * value,  ASTNodeArg* next);

ASTValue* createInt64Value(uint64_t val);
ASTValue* createDoubleValue(double val);
ASTValue* createStrValue(const char* val);

void appendSiblingNode(ASTNode* list, ASTNode* newNode);
void appendSiblingArg(ASTNodeArg* list, ASTNodeArg* newArg);
void appendSiblingValue(ASTValue* list, ASTValue* newValue);

uint16_t countNodes(const ASTNode* n);

const ASTNodeArg* getArgByName(const ASTNode* node, const char* name);
const ASTNode* findNodeByNameInList(const ASTNode* list, const char* name);
const ASTNode* findNodeByNameInTree(const ASTNode* tree, const char* name);

void printASTValueUnion(FILE* file, const ASTValue* value);
void printASTValue(FILE* file, const ASTValue* value);
void printASTArgs(FILE* file, const ASTNodeArg* args);
void printTrees(FILE* file, const ASTNode* trees, int indent);

ASTNode* parseFile(FILE* in);
ASTNode* parseString(const char* in);

#ifdef __cplusplus
}
#endif

#endif // AST_H
