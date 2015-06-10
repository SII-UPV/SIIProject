/*
#include <QCoreApplication>

#include <osg/Version>
#include <osg/Group>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

    printf("Hello\n");
    printf("version %s\n",osgGetVersion());

     //Creating the viewer
     osgViewer::Viewer viewer;

     //Creating the root node
     osg::ref_ptr<osg::Group> root (new osg::Group);

     //The geode containing our shape
     osg::ref_ptr<osg::Geode> myshapegeode (new osg::Geode);

     //Our shape: a capsule, it could have been any other geometry (a box, plane, cylinder etc.)
     osg::ref_ptr<osg::Capsule> myCapsule (new osg::Capsule(osg::Vec3f(),1,2));

     //Our shape drawable
     osg::ref_ptr<osg::ShapeDrawable> capsuledrawable (new osg::ShapeDrawable(myCapsule.get()));

     myshapegeode->addDrawable(capsuledrawable.get());

     root->addChild(myshapegeode.get());

     if(osgDB::readNodeFile( "cow.osg" ))
         printf("success reading node file\n");
     else
         printf("fail reading node file\n");
     osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "cow.osg" );
     //osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "cessna.osg" );
     //osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "tetera.osgb" );
     //osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "tetera.3ds" );
     //osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "Terrain2.3ds" );

     root->addChild( model.get() );

    viewer.setSceneData( root.get() );
    viewer.run();

    printf("Bye\n");
    while(1);

//    return a.exec();
}
*/


#include <osg/Node>
#include <osg/PositionAttitudeTransform>
#include <osgDB/ReadFile>
//So now we have a scene graph made up of a root node with two children, one is a geometric model of a cessna. The other child is a sub-tree consisting of a transform node with a geometric model of a tank as its only child. To view the scene, we will need to set up a viewer and a simulation loop. Here's how:
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>

int main(int argc, char *argv[])
{
osg::Node* cessnaNode = NULL;
osg::Node* cowNode = NULL;
osg::Node* terrainNode = NULL;
osg::Node* tortugaNode = NULL;

cessnaNode = osgDB::readNodeFile("cessna.osg");
cowNode = osgDB::readNodeFile("cow.osg");
terrainNode = osgDB::readNodeFile("Terrain2.3ds");
//tortugaNode = osgDB::readNodeFile("tortuga.stl");
//tortugaNode = osgDB::readNodeFile("TextDSII.stl");
tortugaNode = osgDB::readNodeFile("tetera.osgb");


//That's everything required to load a database. Next we'll add it as part of a scene graph. Load the model as a child of a transform node so we can reposition the model.
// Declare a node which will serve as the root node
// for the scene graph. Since we will be adding nodes
// as 'children' of this node we need to make it a 'group'
// instance.
// The 'node' class represents the most generic version of nodes.
// This includes nodes that do not have children (leaf nodes.)
// The 'group' class is a specialized version of the node class.
// It adds functions associated with adding and manipulating
// children.

osg::Group* root = new osg::Group();
root->addChild(cessnaNode);
root->addChild(terrainNode);

// Declare transform, initialize with defaults.

osg::PositionAttitudeTransform* cowXform = new osg::PositionAttitudeTransform();
osg::PositionAttitudeTransform* tortugaXform = new osg::PositionAttitudeTransform();

// Use the 'addChild' method of the osg::Group class to
// add the transform as a child of the root node and the
// tank node as a child of the transform.

root->addChild(cowXform);
cowXform->addChild(cowNode);
root->addChild(tortugaXform);
tortugaXform->addChild(tortugaNode);

// Declare and initialize a Vec3 instance to change the
// position of the tank model in the scene
osg::Vec3 cowPosit(5,0,0);
cowXform->setPosition( cowPosit );
osg::Vec3 tortugaPosit(0,20,0);
tortugaXform->setPosition( tortugaPosit );



// Declare a 'viewer'
osgViewer::Viewer viewer;

// Next we will need to assign the scene graph we created
// above to this viewer:
viewer.setSceneData( root );

// attach a trackball manipulator to all user control of the view
viewer.setCameraManipulator(new osgGA::TrackballManipulator);

// create the windows and start the required threads.
viewer.realize();

// Enter the simulation loop. viewer.done() returns false
// until the user presses the 'esc' key.
// (This can be changed by adding your own keyboard/mouse
// event handler or by changing the settings of the default
// keyboard/mouse event handler)

while( !viewer.done() )
{
   // dispatch the new frame, this wraps up the follow Viewer operations:
   //   advance() to the new frame
   //   eventTraversal() that collects events and passes them on to the event handlers and event callbacks
   //   updateTraversal() to calls the update callbacks
   //   renderingTraversals() that runs syncronizes all the rendering threads (if any) and dispatch cull, draw and swap buffers
   viewer.frame();
}
}
