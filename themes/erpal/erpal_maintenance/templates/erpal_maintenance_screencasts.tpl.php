<h3 class="title">Do you want to learn something about ERPAL during the installation process?</h3>
  <div class="clear">
    <?php if(isset($screencasts)): ?>
      <?php foreach ($screencasts as $screencast): ?>
        <div class="video-box">
          <?php print('<a href="'.$screencast['link'].'" target= "blank">') ?>
            <?php print('<img width="170" height="130" src="' . $screencast['image'] . '"></img>') ?><br/>
            <?php print($screencast['title']) ?>
          <?php print('</a>') ?>
        </div>
      <?php endforeach; ?>
    <?php else: ?>
      <p>Feel free to visit our <a href= "http://www.youtube.com/user/ScreencastsERPAL?feature=watch" target= 'blank'>Youtube-Channel</a></p>
    <?php endif; ?>
  </div>