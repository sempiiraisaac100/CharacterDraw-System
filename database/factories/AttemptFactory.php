<?php

namespace Database\Factories;

use App\Models\Attempt;
use Illuminate\Database\Eloquent\Factories\Factory;

class AttemptFactory extends Factory
{
    /**
     * The name of the factory's corresponding model.
     *
     * @var string
     */
    protected $model = Attempt::class;

    /**
     * Define the model's default state.
     *
     * @return array
     */
    public function definition()
    {
        return [
            'pupil_id' => $this->faker->randomDigitNotNull,
        'assignment_id' => $this->faker->randomDigitNotNull,
        'average_score' => $this->faker->randomDigitNotNull,
        'attempt_duration_in_seconds' => $this->faker->randomDigitNotNull,
        'teacher_comment' => $this->faker->word,
        'deleted_at' => $this->faker->date('Y-m-d H:i:s'),
        'created_at' => $this->faker->date('Y-m-d H:i:s'),
        'updated_at' => $this->faker->date('Y-m-d H:i:s')
        ];
    }
}
