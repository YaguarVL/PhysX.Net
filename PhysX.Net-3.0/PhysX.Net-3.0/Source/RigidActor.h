#pragma once

#include "Actor.h"

namespace PhysX
{
	ref class Shape;
	ref class Geometry;
	ref class Material;

	/// <summary>
	/// RigidActor represents a base class shared between dynamic and static rigid bodies in the physics SDK.
	/// </summary>
	public ref class RigidActor abstract : Actor
	{
		private:
			List<Shape^>^ _shapes;

		internal:
			RigidActor(PxRigidActor* rigidActor, PhysX::Physics^ owner);
		public:
			~RigidActor();
		protected:
			!RigidActor();

		public:
			/// <summary>
			/// Creates a new shape with default properties and a single material adds it to the list of shapes of this actor.
			/// </summary>
			/// <remarks>
			/// Mass properties of dynamic rigid actors will not automatically be recomputed to reflect the new mass distribution
			/// implied by the shape. Follow this call with a call to the PhysX extensions method RigidBodyExt.UpdateMassAndInertia() to do that.
			/// The default shape flags to be set are: Visualization, SimulationShape, SceneQueryShape (see <see cref="ShapeFlag" />).
			/// The only exception are triangle mesh, heightfield or plane geometry shapes if the actor is not a PxRigidStatic.
			/// In these cases the SimulationShape flag is omitted.
			/// Creating compounds with a very large number of shapes may adversly affect performance and stability.
			/// 
			/// Does NOT wake the actor up automatically.
			/// </remarks>
			/// <param name="geometry">The geometry of the shape.</param>
			/// <param name="material">The material for the shape.</param>
			/// <param name="localPose">Optional actor-relative pose of the shape.</param>
			/// <returns>The newly created shape.</returns>
			Shape^ CreateShape(Geometry^ geometry, Material^ material, [Optional] Nullable<Matrix> localPose);

			/// <summary>
			/// Retrieves the actors world space transform.
			/// </summary>
			/// <remarks>
			///	The GlobalPose property retrieves the actor's current actor space to world space transformation.
			/// </remarks>
			property Matrix GlobalPose
			{
				Matrix get();
				void set(Matrix value);
			}

			/// <summary>
			/// Gets the shapes associated to this rigid actor.
			/// </summary>
			property IEnumerable<Shape^>^ Shapes
			{
				IEnumerable<Shape^>^ get();
			}

		internal:
			property PxRigidActor* UnmanagedPointer
			{
				PxRigidActor* get();
			}
	};
};