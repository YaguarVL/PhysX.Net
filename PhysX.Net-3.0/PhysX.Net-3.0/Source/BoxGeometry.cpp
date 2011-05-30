#include "StdAfx.h"
#include "BoxGeometry.h"
#include <PxBoxGeometry.h>

using namespace PhysX;

BoxGeometry::BoxGeometry()
	: Geometry(GeometryType::Box)
{
	this->HalfExtents = Vector3::Zero;
}
BoxGeometry::BoxGeometry(float hX, float hY, float hZ)
	: Geometry(GeometryType::Box)
{
	this->HalfExtents = Vector3(hX, hY, hZ);
}
BoxGeometry::BoxGeometry(Vector3 halfExtents)
	: Geometry(GeometryType::Box)
{
	this->HalfExtents = halfExtents;
}

PxGeometry* BoxGeometry::ToUnmanaged()
{
	PxVec3 v = MathUtil::Vector3ToPxVec3(this->HalfExtents);

	return new PxBoxGeometry(v);
}