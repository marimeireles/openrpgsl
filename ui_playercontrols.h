
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *trackName;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    Player *widget;

        horizontalLayout_2 = new QHBoxLayout(track);
        verticalLayout_4 = new QVBoxLayout();
        trackName = new QLabel(track);

        verticalLayout_4->addWidget(trackName);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        widget = new Player(track);

        verticalLayout_2->addWidget(widget);


        horizontalLayout_2->addLayout(verticalLayout_2);

