/*
 * ConsistentPhrase.cpp
 *
 *  Created on: 20 Feb 2014
 *      Author: hieu
 */
#include <sstream>
#include "ConsistentPhrase.h"
#include "Word.h"
#include "NonTerm.h"

using namespace std;

ConsistentPhrase::ConsistentPhrase(
		int sourceStart, int sourceEnd,
		int targetStart, int targetEnd)
:corners(4)
{
	if (sourceStart == 0 && targetStart == 15) {
		cerr << "oh dear";
	}
	corners[0] = sourceStart;
	corners[1] = sourceEnd;
	corners[2] = targetStart;
	corners[3] = targetEnd;
}

ConsistentPhrase::~ConsistentPhrase() {
	// TODO Auto-generated destructor stub
}

bool ConsistentPhrase::operator<(const ConsistentPhrase &other) const
{
  return corners < other.corners;
}

void ConsistentPhrase::AddNonTerms(const std::string &source,
					const std::string &target)
{
	m_nonTerms.push_back(NonTerm(*this, source, target));
}

bool ConsistentPhrase::TargetOverlap(const ConsistentPhrase &other) const
{
	if ( other.corners[3] < corners[2] || other.corners[2] > corners[3])
		return false;

	return true;
}

std::string ConsistentPhrase::Debug() const
{
  stringstream out;
  out << "[" << corners[0] << "-" << corners[1]
		  << "][" << corners[2] << "-" << corners[3] << "]";

  return out.str();
}


