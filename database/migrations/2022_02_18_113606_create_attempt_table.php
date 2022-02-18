<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateAttemptTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('attempt', function (Blueprint $table) {
            $table->id();
            $table->integer('pupil_id');
            $table->integer('assignment_id');
            $table->double('average_score');
            $table->double('attempt_duration_in_seconds');
            $table->string("teacher_comment");
            $table->datetime('deleted_at')->nullable();
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('attempt');
    }
}
