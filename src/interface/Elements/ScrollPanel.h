// Exemplozinho se alguém for mexer nisso:
// https://github.com/raysan5/raygui/blob/master/examples/scroll_panel/scroll_panel.c

#ifndef UI_SCROLLPANEL_H
#define UI_SCROLLPANEL_H

#include "./Frames/Frame.h"
#include "./Frames/ScrollableFrame.h"

// Não deletar o child por fora, a própria classe cuida disso
class ScrollPanel : public Frame{
        public:
        void render() override;

        ScrollPanel(Rectangle bounds_, ScrollableFrame* child_);

        ~ScrollPanel() override;

    private:
        Vector2 scroll;
        Rectangle view;

        Rectangle panelRec;
        Rectangle panelContentRec;

        ScrollableFrame* child;

        // Não tou usando isso mas caso a gente queira estilizar alguma hora, esse código do exemplo tá bem organizadinho
        //void DrawStyleEditControls(void);
};

#endif // UI_SCROLLPANEL_H