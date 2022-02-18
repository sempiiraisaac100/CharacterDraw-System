<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;

class DatabaseSeeder extends Seeder
{
    /**
     * Seed the application's database.
     *
     * @return void
     */
    public function run()
    {
        \App\Models\Teacher::factory(10)->create();
        \App\Models\Pupil::factory(10)->create();
        \App\Models\Assignment::factory(10)->create();
        \App\Models\RequestModel::factory(10)->create();
        \App\Models\Attempt::factory(10)->create();
        \App\Models\User::factory(10)->create();
   

    }
}
