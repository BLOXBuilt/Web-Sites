<?php 
global $qode_pitch_options;
$title_tag="h5";
if(isset($qode_pitch_options['blog_single_title_tags'])){
    $title_tag = $qode_pitch_options['blog_single_title_tags'];
}
$headings_array = array('h2', 'h3', 'h4', 'h5', 'h6');
//get correct heading value
$title_tag = (in_array($title_tag, $headings_array)) ? $title_tag : 'h5';

$pagination_classes = '';
if( isset($qode_pitch_options['pagination_type']) && $qode_pitch_options['pagination_type'] == 'standard' ) {
	if( isset($qode_pitch_options['pagination_standard_position']) && $qode_pitch_options['pagination_standard_position'] !== '' ) {
		$pagination_classes .= "standard_".esc_attr($qode_pitch_options['pagination_standard_position']);
	}
}
elseif ( isset($qode_pitch_options['pagination_type']) && $qode_pitch_options['pagination_type'] == 'arrows_on_sides' ) {
	$pagination_classes .= "arrows_on_sides";
}
?>

<div class="comment_holder clearfix" id="comments">
<div class="comment_number"><div class="comment_number_inner"><<?php echo esc_attr($title_tag); ?>><?php comments_number( esc_html__('No Comments','pitchwp'), esc_html__(' Comments: ','pitchwp'), esc_html__(' Comments: ','pitchwp')); ?></<?php echo esc_attr($title_tag); ?>></div></div>
<div class="comments">
<?php if ( post_password_required() ) : ?>
				<p class="nopassword"><?php esc_html_e( 'This post is password protected. Enter the password to view any comments.', 'pitchwp' ); ?></p>
			</div></div>
<?php
		
		return;
	endif;
?>
<?php if ( have_comments() ) : ?>

	<ul class="comment-list <?php if(isset($qode_pitch_options['blog_comments_reply_link_on_bottom_yes_no'])&& $qode_pitch_options['blog_comments_reply_link_on_bottom_yes_no']=='yes' ) echo "bottom-comment-link" ;?>">
		<?php wp_list_comments(array( 'callback' => 'qode_pitch_comment')); ?>
	</ul>


<?php // End Comments ?>

 <?php else : // this is displayed if there are no comments so far 

	if ( ! comments_open() ) :
?>
		<!-- If comments are open, but there are no comments. -->

	 
		<!-- If comments are closed. -->
		<p><?php esc_html_e('Sorry, the comment form is closed at this time.', 'pitchwp'); ?></p>

	<?php endif; ?>
<?php endif; ?>
</div></div>
<?php
$commenter = wp_get_current_commenter();
$req = get_option( 'require_name_email' );
$aria_req = ( $req ? " aria-required='true'" : '' );

$args = array(
	'id_form' => 'commentform',
	'id_submit' => 'submit_comment',
	'title_reply'=>'<'.$title_tag.'>'. esc_html__( 'Leave a Comment:','pitchwp' ) .'</'.$title_tag.'>',
	'title_reply_to' => esc_html__( 'Post a Reply to %s','pitchwp' ),
	'cancel_reply_link' => esc_html__( 'Cancel Reply','pitchwp' ),
	'label_submit' => esc_html__( 'Submit','pitchwp' ),
	'comment_field' => '<textarea id="comment" placeholder="'.esc_html__( 'Write your comment here...','pitchwp' ).'" name="comment" cols="45" rows="8" aria-required="true"></textarea>',
	'comment_notes_before' => '',
	'comment_notes_after' => '',
	'fields' => apply_filters( 'comment_form_default_fields', array(
		'author' => '<div class="three_columns clearfix"><div class="column1"><div class="column_inner"><input id="author" name="author" placeholder="'. esc_html__( 'Your full name','pitchwp' ) .'" type="text" value="' . esc_attr( $commenter['comment_author'] ) . '"' . $aria_req . ' /></div></div>',
		'url' => '<div class="column2"><div class="column_inner"><input id="email" name="email" placeholder="'. esc_html__( 'E-mail address','pitchwp' ) .'" type="text" value="' . esc_attr(  $commenter['comment_author_email'] ) . '"' . $aria_req . ' /></div></div>',
		'email' => '<div class="column3"><div class="column_inner"><input id="url" name="url" type="text" placeholder="'. esc_html__( 'Website','pitchwp' ) .'" value="' . esc_attr( $commenter['comment_author_url'] ) . '" /></div></div></div>'
		 ) ) );
 ?>
<?php if(get_comment_pages_count() > 1){
	?>
	<div class="comment_pager <?php echo esc_attr($pagination_classes); ?>">
		<p><?php paginate_comments_links(); ?></p>
	</div>
<?php } ?>
 <div class="comment_form">
	<?php comment_form($args); ?>
</div>
								
							


