# include "btBulletDynamicsCommon.h"
# include <stdio.h>
// This is a Hello World program for running a basic Bullet physics simulation
int main (int argc,char** argv)
{
 // Initialize the dynamic world
  
 // collision configuration contains default setup for memory , collision setup . Advanced users can create their own configuration .
  btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
  
// use the default collision dispatcher . For parallel processing you can use a different dispatcher ( see Extras / BulletMultiThreaded )
  btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
  
// btDbvtBroadphase is a good general purpose broadphase . You can also try out btAxis3Sweep .
  btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
  
// the default constraint solver . For parallel processing you can use a different solver( see Extras / BulletMultiThreaded )
  btSequentialImpulseConstraintSolver * solver = new btSequentialImpulseConstraintSolver;
  btDiscreteDynamicWorld* dynamicsWorld = new btDiscreteDynamicWorld (dispatcher,overlappingPairCache,solver,collisionConfiguration);
  dynamicsWorld->setGravity(btVector3 (0,-10,0));

for (i =0;i<100;i ++)
{
  dynamicsWorld->stepSimulation (1.f/60.f,10) ;
  
// print positions of all objects
  for (int j=dynamicsWorld->get NumCollisionObjects()-1;j>=0;j--)
  {
   btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
   btRigidBody* body = btRigidBody::upcast(obj);
   btTransform trans ;
   if ( body && body->getMotionState())
    {
     body->getMotionState()->getWorldTransform (trans);
    } else
    {
     trans = obj->getWorldTransform();
    }
    printf ( "world pos object % d = %f ,% f ,% f \n " ,j , float(trans.getOrigin().getX()),float(trans.getOrigin().getY()),float(trans.getOrigin().getZ()));
   }
}
 
 // remove the rigidbodies from the dynamics world and delete them
 for (i=dynamicsWorld->getNumCollisionObjects()-1;i>=0;i--)
  {
    btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
    btRigidBody* body = btRigidBody::upcast(obj);
    if ( body && body->getMotionState())
    {
     delete body->getMotionState();
    }
     dynamicsWorld->removeCollisionObject(obj);
     delete obj;
  }
// delete collision shapes
for (int j=0;j<collisionShapes.size();j++)
 {
   btCollisionShape* shape = collisionShapes[j];
   collisionShapes[j]=0;
   delete shape;
 }
// delete dynamics world
delete dynamicsWorld;
// delete solver
delete solver;
// delete broadphase
delete overlappingPairCache;
// delete dispatcher
delete dispatcher;
delete collisionConfiguration;
 
 //Optional
collisionShapes.clear();
