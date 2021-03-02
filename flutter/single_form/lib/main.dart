import 'package:flutter/material.dart';
import 'package:single_form/videoPlayer.dart';

void main() => runApp(VideoApp());

/* void main() => runApp(
      MaterialApp(
        title: 'test app',
        home: App(),
      ),
    );
*/

class App extends StatefulWidget {
  @override
  _AppState createState() => _AppState();
}

class _AppState extends State<App> {
  @override
  Widget build(BuildContext context) {
    return Material(
      child: Column(
        children: <Widget>[
          TopPanel(
            title: Text(
              'working...',
              style: Theme.of(context).primaryTextTheme.headline4,
            ),
          ),
        ],
      ),
    );
  }
}

class TopPanel extends StatelessWidget {
  TopPanel({this.title});
  final Widget title;

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 56.0,
      padding: const EdgeInsets.symmetric(horizontal: 8.0),
      decoration: BoxDecoration(color: Colors.black26),
      child: Row(
        children: <Widget>[
          IconButton(
            icon: Icon(Icons.menu),
            tooltip: 'Navigation menu',
            onPressed: null,
          ),
          Expanded(
            child: title,
          ),
          IconButton(
            icon: Icon(Icons.search),
            tooltip: 'Search',
            onPressed: null,
          ),
        ],
      ),
    );
  }
}
