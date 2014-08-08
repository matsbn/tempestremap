///////////////////////////////////////////////////////////////////////////////
///
///	\file    MeshUtilitiesExact.h
///	\author  Paul Ullrich
///	\version August 7, 2014
///
///	<remarks>
///		Copyright 2000-2014 Paul Ullrich
///
///		This file is distributed as part of the Tempest source code package.
///		Permission is granted to use, copy, modify and distribute this
///		source code and its documentation under the terms of the GNU General
///		Public License.  This software is provided "as is" without express
///		or implied warranty.
///	</remarks>

#ifndef _MESHUTILITIESEXACT_H_
#define _MESHUTILITIESEXACT_H_

#include "GridElements.h"

#include <vector>

///////////////////////////////////////////////////////////////////////////////

///	<summary>
///		Various implementations of methods for determining Faces from Nodes.
///	</summary>
class MeshUtilitiesExact {

public:
	///	<summary>
	///		Determine if two Nodes are equal.
	///	</summary>
	bool AreNodesEqual(
		const Node & node0,
		const Node & node1
	);

	///	<summary>
	///		Calculate all intersections between the Edge connecting
	///		nodeFirstBegin and nodeFirstEnd with type typeFirst and the Edge
	///		connecting nodeSecondBegin and nodeSecondEnd with type typeSecond.
	///		Intersections are recorded in nodeIntersections.
	///	</summary>
	///	<returns>
	///		Returns true if lines are coincident, false otherwise.
	///
	///		If lines are coincident, intersections includes any nodes of Second
	///		that are contained in First, ordered from FirstBegin to FirstEnd.
	///	</returns>
	bool CalculateEdgeIntersections(
		const Node & nodeFirstBegin,
		const Node & nodeFirstEnd,
		Edge::Type typeFirst,
		const Node & nodeSecondBegin,
		const Node & nodeSecondEnd,
		Edge::Type typeSecond,
		std::vector<Node> & nodeIntersections,
		bool fIncludeFirstBeginNode = false
	);

	///	<summary>
	///		Find all Face indices that contain this Node.
	///	</summary>
	void FindFaceFromNode(
		const Mesh & mesh,
		const Node & node,
		FindFaceStruct & aFindFaceStruct
	);

	///	<summary>
	///		Find the Face that is near ixNode in the direction of nodeEnd.
	///	</summary>
	int FindFaceNearNode(
		const Mesh & mesh,
		int ixNode,
		const Node & nodeEnd,
		const Edge::Type edgetype
	);

	///	<summary>
	///		Find the Face that is near nodeBegin in the direction of nodeEnd.
	///	</summary>
	int FindFaceNearNode(
		const Mesh & mesh,
		const Node & nodeBegin,
		const Node & nodeEnd,
		const Edge::Type edgetype,
		const FindFaceStruct & aFindFaceStruct
	);
};

///////////////////////////////////////////////////////////////////////////////

#endif
