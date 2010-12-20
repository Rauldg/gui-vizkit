#ifndef __VIZKIT_QVIZKITWIDGET__
#define __VIZKIT_QVIZKITWIDGET__

#include <vizkit/QOSGWidget.hpp>
#include <vizkit/VizPlugin.hpp>
#include <vizkit/CompositeViewerQOSG.hpp>
#include <vizkit/PickHandler.hpp>

namespace vizkit 
{

class QVizkitWidget : public CompositeViewerQOSG 
{
    Q_OBJECT

public:
    QVizkitWidget( QWidget* parent = 0, Qt::WindowFlags f = 0 );
    osg::ref_ptr<osg::Group> getRootNode() const;

    void addDataHandler(VizPluginBase *viz);
    void removeDataHandler(VizPluginBase *viz);

    QSize sizeHint() const;

protected:
    osg::ref_ptr<osg::Group> root;
    void createSceneGraph();
    osg::ref_ptr<PickHandler> pickHandler;

    osg::ref_ptr<ViewQOSG> view;
};

}

#endif